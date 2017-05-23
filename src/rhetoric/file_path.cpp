#include "./file_path.h"

namespace rhetoric {
    FilePath::FilePath():
    type_(Type::Relative)
    {}

    FilePath::FilePath(const std::string & string) {
        *this = Parse(string);
    }

    FilePath::FilePath(const FilePath & other) {
        *this = other;
    }

    FilePath & FilePath::operator= (const FilePath & other) {
        type_ = other.type_;
        drive_letter_ = other.drive_letter_;
        elements_ = other.elements_;
        return *this;
    }

    FilePath::Type FilePath::type() const {
        return type_;
    }

    const Optional<std::string> & FilePath::drive_letter() const {
        return drive_letter_;
    }

    const std::vector<std::string> & FilePath::elements() const {
        return elements_;
    }

    std::string FilePath::ToString() const {
        std::string str;

        if (type_ == Type::Absolute) {
            if (drive_letter_) {
                str += *drive_letter_ + ":";
            }

            str += separator();
        }

        str += Join(elements_, separator());
        return str;
    }

    bool FilePath::operator==(const FilePath & other) const {
        return (type_ == other.type_ &&
                drive_letter_ == other.drive_letter_ &&
                elements_ == other.elements_);
    }

    bool FilePath::operator!=(const FilePath & other) const {
        return !(*this == other);
    }

    bool FilePath::is_root() const {
        if (type_ == Type::Absolute && elements_.size() == 0) {
            return true;
        }
        return false;
    }

    FilePath FilePath::parent() const {
        FilePath ret(*this);

        while (true) {
            if (ret.elements_.size() == 0) {
                if (type_ == Type::Absolute) {
                    RHETORIC_FATAL(GenericError::Create("path=%s", ToString().c_str())->ToString());
                }

                ret.elements_.push_back("..");

                return ret;
            }

            auto last_iter = ret.elements_.end() - 1;
            auto last = *last_iter;
            if (last == "" || last == ".") {
                ret.elements_.erase(last_iter);
                continue;
            }

            if (last == "..") {
                ret.elements_.push_back("..");
                return ret;
            }

            ret.elements_.erase(last_iter);
            return ret;
        }
    }

    Result<std::vector<FilePath>> FilePath::GetChildren() const {
        std::string str = ToString();
        DIR * handle = opendir(str.c_str());
        if (!handle) {
            return Failure(PosixError::Create(errno, "opendir(%s)", str.c_str()));
        }

        RHETORIC_DEFER([=] {
            if (closedir(handle)) {
                RHETORIC_FATAL(PosixError::Create(errno, "closedir: %s", str.c_str())->ToString());
            }
        });

        std::vector<FilePath> ret;

        dirent * entry;
        errno = 0;
        while (true) {
            entry = readdir(handle);
            if (!entry) {
                if(errno) {
                    return Failure(PosixError::Create(errno, "readdir: %s", str.c_str()));
                }
                break;
            }

            auto name = std::string(entry->d_name);
            if (name == "." || name == "..") {
                continue;
            }
            
            ret.push_back(*this + FilePath(name));
        }
        
        return Success(ret);
    }

    FilePath FilePath::basename() const {
        if (elements_.size() == 0) {
            return FilePath("");
        }
        return FilePath(elements_.back());
    }

    void FilePath::set_basename(const FilePath & value) {
        RHETORIC_ASSERT(value.type_ == Type::Relative);
        RHETORIC_ASSERT(value.elements_.size() == 1);

        if (elements_.size() == 0) {
            Append(value);
        } else {
            elements_.back() = value.ToString();
        }
    }

    Optional<std::string> FilePath::extension() const {
        auto strs = SplitR(basename().ToString(), ".", Some(2));
        if (strs.size() < 2) {
            return None();
        }
        return Some(strs[1]);
    }

    void FilePath::set_extension(const Optional<std::string> & value) {
        auto strs = SplitR(basename().ToString(), ".", Some(2));

        std::string name;
        if (strs.size() == 0) {
            name = "";
        } else {
            name = strs[0];
        }

        if (value) {
            name += "." + *value;
        }

        set_basename(FilePath(name));
    }

    void FilePath::Append(const FilePath & path) {
        RHETORIC_ASSERT(path.type_ == Type::Relative);
        elements_.insert(elements_.end(),
                         path.elements_.begin(),
                         path.elements_.end());
    }

    FilePath FilePath::operator+(const FilePath & other) const {
        FilePath ret(*this);
        ret.Append(other);
        return ret;
    }

    void FilePath::Normalize() {
        *this = Normalized();
    }

    FilePath FilePath::Normalized() const {
        FilePath ret(*this);

        ret.elements_.clear();

        for (auto & element : elements_) {
            if (element == "" || element == ".") {
                continue;
            }
            if (element == "..") {
                if (ret.elements_.size() > 0) {
                    ret.elements_.erase(ret.elements_.end() - 1);
                }
                continue;
            }
            ret.elements_.push_back(element);
        }

        return ret;
    }

    void FilePath::Expand() {
        *this = Expanded();
    }

    FilePath FilePath::Expanded() const {
        FilePath ret;

        switch (type_) {
            case Type::Relative:
                ret = current() + *this;
                break;
            case Type::Absolute:
                ret = *this;
                break;
        }

        ret.Normalize();

        return ret;
    }

    Result<bool> FilePath::GetExists() const {
        auto st = GetStat();
        if (st.err == ENOENT) {
            return Success(false);
        }
        if (st.err != 0) {
            return Failure(PosixError::Create(st.err, "stat(%s)", ToString().c_str()));
        }
        return Success(true);
    }

    Result<Optional<FileEntryType>> FilePath::GetEntryType() const {
        auto st = GetStatResult();
        if (st.err == ENOENT) {
            return Success(None());
        }
        if (st.err != 0) {
            return Failure(PosixError::Create(st.err, "stat(%s)", ToString().c_str()));
        }

        FileEntryType entry_type;
        if (S_ISREG(st.st.st_mode)) {
            entry_type = FileEntryType::File;
        } else if (S_ISDIR(st.st.st_mode)) {
            entry_type = FileEntryType::Directory;
        } else {
            entry_type = FileEntryType::Other;
        }
        return Success(Some(entry_type));
    }

    Result<None> FilePath::CreateDirectory(bool recursive) const {
        if (!recursive) {
            return CreateDirectorySingle();
        }

        FilePath path = Normalized();
        FilePath create_path(path);
        create_path.elements_.clear();

        for (auto element : path.elements_) {
            create_path.Append(FilePath(element));

            auto create_ret = create_path.CreateDirectorySingle();
            if (!create_ret) {
                return Failure(GenericError::Create(create_ret.error(),
                                                    "CreateDirectorySingle: path=%s",
                                                    ToString().c_str()));
            }
        }

        return Success(None());
    }

    std::string FilePath::separator() {
#if RHETORIC_MACOS
        return "/";
#elif RHETORIC_WINDOWS
        return "\\";
#endif
    }

    FilePath FilePath::current() {
#if RHETORIC_MACOS
        char * cstr = getcwd(nullptr, 0);
        if (!cstr) {
            RHETORIC_FATAL(PosixError::Create(errno, "getcwd")->ToString());
        }
        RHETORIC_DEFER([=] { free(cstr); });
        return FilePath(std::string(cstr));
#elif RHETORIC_WINDOWS

#endif
    }

    FilePath FilePath::home() {
#if RHETORIC_MACOS
        char * cstr = getenv("HOME");
        if (!cstr) {
            RHETORIC_FATAL("HOME is null");
        }
        return FilePath(std::string(cstr));
#elif RHETORIC_WINDOWS
#endif
    }

    FilePath::FilePath(Type type,
                       const Optional<std::string> & drive_letter,
                       const std::vector<std::string> & elements):
    type_(type),
    drive_letter_(drive_letter),
    elements_(elements)
    {
    }

    FilePath::GetStatResult::GetStatResult() {
        memset(&st, 0, sizeof(st));
        err = 0;
    }

    FilePath::GetStatResult FilePath::GetStat() const {
        GetStatResult ret;
        int x = stat(ToString().c_str(), &ret.st);
        if (x == -1) {
            ret.err = errno;
            return ret;
        }
        return ret;
    }

    Result<None> FilePath::CreateDirectorySingle() const {
        std::string path = ToString();
        int t = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
        if (t == -1) {
            return Failure(PosixError::Create(errno, "mkdir(%s)", path.c_str()));
        }
        return Success(None());
    }

    FilePath FilePath::Parse(const std::string & string) {
        std::vector<std::string> separators = { "/" };
#if RHETORIC_WINDOWS
        separators.push_back("\\");
#endif

        auto elements = Split(string, separators);

        if (elements.size() == 0) {
            return FilePath(Type::Relative, None(), {});
        }

        auto head = elements[0];

        if (head.size() == 0) {
            return FilePath(Type::Absolute, None(),
                            std::vector<std::string>(elements.begin() + 1,
                                                     elements.end()));
        }

#if RHETORIC_WIDNOWS
        if (IsEndWith(head, ":")) {
            return FilePath(Type::Absolute,
                            Some(head.substr(0, head.size() - 1)),
                            std::vector<std::string>(elements.begin() + 1,
                                                     elements.end()));
        }
#endif

        return FilePath(Type::Relative, None(), elements);
    }

}

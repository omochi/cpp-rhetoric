#include "./file_path.h"

#include "./file_stream.h"

namespace rhetoric {
	FilePath::FilePath() :
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

            auto last = ret.elements_.back();
			if (last == "" || last == ".") {
                ArrayRemoveAt(&ret.elements_, ret.elements_.size() - 1);
				continue;
			}

			if (last == "..") {
				ret.elements_.push_back("..");
				return ret;
			}
            
            ArrayRemoveAt(&ret.elements_, ret.elements_.size() - 1);
			return ret;
		}
	}

#if RHETORIC_MACOS
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
				if (errno) {
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
#endif

#if RHETORIC_WINDOWS
	Result<std::vector<FilePath>> FilePath::GetChildren() const {
		std::string str = ToString();
		WinString winstr = StringToWinString(str, CP_UTF8);

		WIN32_FIND_DATA entry;
		HANDLE handle = FindFirstFile(winstr.c_str(), &entry);
		if (handle == INVALID_HANDLE_VALUE) {
			return Failure(Win32Error::Create(GetLastError(), "FindFirstFile(%s)", str.c_str()));
		}

		RHETORIC_DEFER([=] {
			BOOL close_ret = FindClose(handle);
			if (!close_ret) {
				RHETORIC_FATAL(Win32Error::Create(GetLastError(), "FindClose: %s", str.c_str())->ToString());
			}
		});

		std::vector<FilePath> ret;

		for (int count = 0; ; count++) {
			if (count != 0) {
				BOOL next_ret = FindNextFile(handle, &entry);
				if (!next_ret) {
					DWORD error = GetLastError();
					if (error != ERROR_NO_MORE_FILES) {
						return Failure(Win32Error::Create(error, "FindNextFile: %s", str.c_str()));
					}
					break;
				}
			}

			auto name = WinStringToString(WinString(entry.cFileName), CP_UTF8);
			if (name == "." || name == "..") {
				continue;
			}

			ret.push_back(*this + FilePath(name));
		}

		return Success(ret);
	}
#endif

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
		}
		else {
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

    SplitExtensionResult FilePath::SplitExtension() const {
        auto strs = SplitR(basename().ToString(), ".", Some(2));
        SplitExtensionResult ret;
        if (strs.size() == 2) {
            ret.extension = Some(strs[1]);
        }
        if (strs.size() >= 1) {
            ret.name = strs[0];
        }
        return ret;
    }

    void FilePath::ReplaceExtension(const Optional<std::string> & extension) {
        auto split_ret = SplitExtension();
        std::string new_basename = split_ret.name;
        if (extension) {
            new_basename += "." + *extension;
        }
        set_basename(FilePath(new_basename));
    }

    void FilePath::AppendExtension(const std::string & extension) {
        set_basename(FilePath(basename().ToString() + "." + extension));
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
        struct stat st;
        int x = stat(ToString().c_str(), &st);
        if (x == -1) {
            if (errno == ENOENT) {
                return Success(false);
            }
            return Failure(CreateStatError(errno));
        }
        return Success(true);
	}

	Result<FileEntryType> FilePath::GetEntryType() const {
        RHETORIC_TRY_ASSIGN(auto st, GetStat())

        FileEntryType ret;

		if (S_ISREG(st.st_mode)) {
			ret = FileEntryType::File;
		} else if (S_ISDIR(st.st_mode)) {
			ret = FileEntryType::Directory;
		} else {
			ret = FileEntryType::Other;
		}

        return Success(ret);
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

            RHETORIC_TRY_ASSIGN(auto exi, create_path.GetExists());
			if (exi) {
				continue;
			}

			auto create_ret = create_path.CreateDirectorySingle();
			if (!create_ret) {
                return Failure(GenericError::Create(create_ret.error(),
                                                    "CreateDirectorySingle: path=%s",
                                                    ToString().c_str()));
			}
		}

		return Success(None());
	}

	Result<Ptr<FileStream>> FilePath::Open(const std::string & mode) const {
		return FileStream::Open(*this, mode);
	}

	Result<Ptr<Data>> FilePath::Read() const {
        RHETORIC_TRY_ASSIGN(auto stream, Open("rb"))
        RHETORIC_TRY_ASSIGN(auto data, stream->Read())
		return Success(data);
	}

	Result<None> FilePath::Write(const Ptr<const Data> & data) const {
        RHETORIC_TRY_ASSIGN(auto stream, Open("wb"))
        RHETORIC_TRY_VOID(stream->Write(data))
		return Success(None());
	}

	std::string FilePath::separator() {
#if RHETORIC_MACOS
		return "/";
#elif RHETORIC_WINDOWS
		return "\\";
#endif
	}

#if RHETORIC_MACOS
	FilePath FilePath::current() {
		char * cstr = getcwd(nullptr, 0);
		if (!cstr) {
			RHETORIC_FATAL(PosixError::Create(errno, "getcwd")->ToString());
		}
		RHETORIC_DEFER([=] { free(cstr); });
		return FilePath(std::string(cstr));
	}
#endif

#if RHETORIC_WINDOWS
	FilePath FilePath::current() {
		std::vector<TCHAR> buf(MAX_PATH);
		int ret = GetCurrentDirectory((int)buf.size(), buf.data());
		if (ret == 0) {
			RHETORIC_FATAL(Win32Error::Create(GetLastError(), "GetCurrentDirectory")->ToString());
		}
		WinString str(buf.data());
		return FilePath(WinStringToString(str, CP_UTF8));
	}
#endif

#if RHETORIC_MACOS
    FilePath FilePath::home() {
        auto home = GetEnv("HOME");
        if (!home) {
            RHETORIC_FATAL("HOME is null");
        }
        return FilePath(*home);
    }
#endif

    FilePath::FilePath(Type type,
                       const Optional<std::string> & drive_letter,
                       const std::vector<std::string> & elements):
    type_(type),
    drive_letter_(drive_letter),
    elements_(elements)
    {
    }

    Result<struct stat> FilePath::GetStat() const {
        auto str = ToString();

        struct stat st;
        int x = stat(str.c_str(), &st);
        if (x == -1) {
            return Failure(CreateStatError(errno));
        }

        return Success(st);
    }

    Ptr<PosixError> FilePath::CreateStatError(int err) const {
        return PosixError::Create(err,
                                  "stat(%s)",
                                  ToString().c_str());
    }

#if RHETORIC_MACOS
    Result<None> FilePath::CreateDirectorySingle() const {
        std::string path = ToString();
        int t = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
        if (t == -1) {
            return Failure(PosixError::Create(errno, "mkdir(%s)", path.c_str()));
        }
        return Success(None());
    }
#endif

#if RHETORIC_WINDOWS
	Result<None> FilePath::CreateDirectorySingle() const {
		std::string path = ToString();
		WinString win_path = StringToWinString(path, CP_UTF8);
		BOOL create_ret = ::CreateDirectory(win_path.c_str(), nullptr);
		if (!create_ret) {
			return Failure(Win32Error::Create(GetLastError(), "CreateDirectory(%s)", path.c_str()));
		}
		return Success(None());
	}
#endif

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

#if RHETORIC_WINDOWS
        if (CheckEndWith(head, ":")) {
            return FilePath(Type::Absolute,
                            Some(head.substr(0, head.size() - 1)),
                            std::vector<std::string>(elements.begin() + 1,
                                                     elements.end()));
        }
#endif

        return FilePath(Type::Relative, None(), elements);
    }

}

#pragma once

#include "./std_dependency.h"
#include "./unix_dependency.h"
#include "./windows_dependency.h"

#include "./attribute.h"
#include "./array_function.h"
#include "./concept_macro.h"
#include "./defer.h"
#include "./env.h"
#include "./fatal.h"
#include "./generic_error.h"
#include "./option.h"
#include "./posix_error.h"
#include "./ptr.h"
#include "./result.h"
#include "./string_function.h"
#include "./string_windows.h"
#include "./try_macro.h"
#include "./win32_error.h"


namespace rhetoric {
    class FileStream;

    enum class FileEntryType {
        File = 1,
        Directory = 2,
        Other
    };

    struct SplitExtensionResult {
        std::string name;
        Option<std::string> extension;
    };

    class FilePath {
    public:
        enum class Type {
            Relative = 1,
            Absolute
        };

        FilePath();
        explicit FilePath(const std::string & string);

        FilePath(const FilePath & other);
        FilePath & operator=(const FilePath & other);

        Type type() const;
        const Option<std::string> & drive_letter() const;
        const std::vector<std::string> & elements() const;

        std::string ToString() const;

        bool operator==(const FilePath & other) const;
        RHETORIC_EQUATABLE_DEFAULT(FilePath);

        bool is_root() const;
        FilePath parent() const;

        RHETORIC_NO_DISCARD
        Result<std::vector<FilePath>> GetChildren() const;

        FilePath basename() const;
        void set_basename(const FilePath & value);

        Option<std::string> extension() const;

        SplitExtensionResult SplitExtension() const;
        void ReplaceExtension(const Option<std::string> & extension);
        void AppendExtension(const std::string & extension);

        void Append(const FilePath & path);
        FilePath operator+(const FilePath & other) const;

        void Normalize();
        FilePath Normalized() const;
        void Expand();
        FilePath Expanded() const;

        RHETORIC_NO_DISCARD
        Result<bool> GetExists() const;
        RHETORIC_NO_DISCARD
        Result<FileEntryType> GetEntryType() const;

        RHETORIC_NO_DISCARD
        Result<None> CreateDirectory(bool recursive = false) const;

        RHETORIC_NO_DISCARD
        Result<Ptr<FileStream>> Open(const std::string & mode) const;

        RHETORIC_NO_DISCARD
        Result<Ptr<Data>> Read() const;

        RHETORIC_NO_DISCARD
        Result<None> Write(const Ptr<const Data> & data) const;

        static std::string separator();
        static FilePath current();

#if RHETORIC_MACOS
        static FilePath home();
#endif
    private:
        FilePath(Type type,
                 const Option<std::string> & drive_letter,
                 const std::vector<std::string> & elements);

        RHETORIC_NO_DISCARD
        Result<struct stat> GetStat() const;

        Ptr<PosixError> CreateStatError(int err) const;
        
        RHETORIC_NO_DISCARD
        Result<None> CreateDirectorySingle() const;

        static FilePath Parse(const std::string & string);

        Type type_;
        Option<std::string> drive_letter_;
        std::vector<std::string> elements_;
    };
}

#pragma once

#include "./attribute.h"
#include "./defer.h"
#include "./fatal.h"
#include "./generic_error.h"
#include "./optional.h"
#include "./posix_error.h"
#include "./result.h"
#include "./std_dependency.h"
#include "./string_function.h"
#include "./unix_dependency.h"

namespace rhetoric {
    enum class FileEntryType {
        File = 1,
        Directory = 2,
        Other
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
        const Optional<std::string> & drive_letter() const;
        const std::vector<std::string> & elements() const;

        std::string ToString() const;

        bool operator==(const FilePath & other) const;
        bool operator!=(const FilePath & other) const;

        FilePath parent() const;
        Result<std::vector<FilePath>> GetChildren() const;

        FilePath basename() const;
        void set_basename(const FilePath & value);

        Optional<std::string> extension() const;
        void set_extension(const Optional<std::string> & value);

        void Append(const FilePath & path);
        FilePath operator+(const FilePath & other) const;

        void Normalize();
        FilePath Normalized() const;
        void Expand();
        FilePath Expanded() const;

        Result<bool> GetExists() const;
        Result<Optional<FileEntryType>> GetEntryType() const;

        static std::string separator();
        static FilePath current();
        static FilePath home();
    private:
        FilePath(Type type,
                 const Optional<std::string> & drive_letter,
                 const std::vector<std::string> & elements);

        struct GetStatResult {
            struct stat st;
            int err;

            GetStatResult();
        };

        GetStatResult GetStat();

        static FilePath Parse(const std::string & string);

        Type type_;
        Optional<std::string> drive_letter_;
        std::vector<std::string> elements_;
    };
}

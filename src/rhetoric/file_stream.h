#pragma once

#include "./file_path.h"
#include "./posix_error.h"
#include "./ptr.h"
#include "./result.h"
#include "./unix_dependency.h"

namespace rhetoric {
    class FileStream {
    public:
        ~FileStream();

        FILE * handle() const;
        FilePath path() const;

        bool closed() const;

        void Close();

        RHETORIC_NO_DISCARD
        Result<int> ReadToBytes(void * bytes, int size);
        
        RHETORIC_NO_DISCARD
        Result<None> WriteFromBytes(const void * bytes, int size);

        RHETORIC_NO_DISCARD
        static Result<Ptr<FileStream>> Open(const FilePath & path,
                                            const std::string & mode);

    private:
        FileStream(FILE * handle,
                   const FilePath & path);

        FILE * handle_;
        FilePath path_;
    };
}

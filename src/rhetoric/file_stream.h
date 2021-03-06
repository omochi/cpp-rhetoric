#pragma once

#include "./std_dependency.h"
#include "./unix_dependency.h"

#include "./crt.h"
#include "./file_path.h"
#include "./format_macro.h"
#include "./posix_error.h"
#include "./ptr.h"
#include "./result.h"
#include "./try_macro.h"

namespace rhetoric {
    class FileStream : public std::enable_shared_from_this<FileStream> {
    public:
        ~FileStream();
        
        RHETORIC_NON_COPYABLE(FileStream)

        FILE * handle() const;
        FilePath path() const;

        bool closed() const;

        void Close();

        RHETORIC_NO_DISCARD
        Result<Ptr<Data>> Read();

        RHETORIC_NO_DISCARD
        Result<Ptr<Data>> Read(size_t size);

        RHETORIC_NO_DISCARD
        Result<size_t> ReadToBytes(void * bytes, size_t size);

        RHETORIC_NO_DISCARD
        Result<None> Write(const Ptr<const Data> & data);

        RHETORIC_NO_DISCARD
        Result<None> WriteFromBytes(const void * bytes, size_t size);

        RHETORIC_NO_DISCARD
        Result<None> Seek(int64_t offset, int whence);

        RHETORIC_NO_DISCARD
        Result<int64_t> GetPosition();

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

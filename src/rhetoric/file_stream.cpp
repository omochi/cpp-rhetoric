#include "./file_stream.h"

namespace rhetoric {
    FileStream::~FileStream() {
        Close();
    }

    FILE * FileStream::handle() const {
        return handle_;
    }

    FilePath FileStream::path() const {
        return path_;
    }

    bool FileStream::closed() const {
        return handle_ == nullptr;
    }

    void FileStream::Close() {
        if (handle_) {
            int t = fclose(handle_);
            if (t) {
                RHETORIC_FATAL(PosixError::Create(errno,
                                                  "fclose: %s",
                                                  path_.ToString().c_str())->ToString());
            }
            handle_ = nullptr;
        }
    }

    Result<Ptr<Data>> FileStream::Read() {
        auto data = New<Data>();

        while (true) {
            RHETORIC_TRY_ASSIGN(auto chunk, Read(1024))
            if (chunk->size() == 0) {
                break;
            }
            data->Append(chunk);
        }

        return Ok(data);
    }

    Result<Ptr<Data>> FileStream::Read(size_t size) {
        Ptr<Data> data = New<Data>(size);

        RHETORIC_TRY_ASSIGN(size_t read_size,
                            ReadToBytes(data->bytes(), data->size()))

        data->set_size(read_size);

        return Ok(data);
    }

    Result<size_t> FileStream::ReadToBytes(void * bytes, size_t size) {
        RHETORIC_ASSERT(!closed());

        size_t len = fread(bytes, 1, size, handle_);
        if (len < size) {
            if (feof(handle_)) {
                return Ok(len);
            }

            return PosixError::Create(ferror(handle_),
                                      "fread(%" PRIdS "): %s",
                                      size,
                                      path_.ToString().c_str());
        }
        return Ok(len);
    }

    Result<None> FileStream::Write(const Ptr<const Data> & data) {
        return WriteFromBytes(data->bytes(), data->size());
    }

    Result<None> FileStream::WriteFromBytes(const void * bytes, size_t size) {
        RHETORIC_ASSERT(!closed());

        size_t len = fwrite(bytes, 1, size, handle_);
        if (len < size) {
            return PosixError::Create(ferror(handle_),
                                      "fwrite(%" PRIdS "): %s",
                                      size,
                                      path_.ToString().c_str());
        }

        return Ok(None());
    }

#if RHETORIC_MACOS
    Result<None> FileStream::Seek(int64_t offset, int whence) {
        RHETORIC_ASSERT(!closed());

        int ret = fseek(handle_, offset, whence);
        if (ret == -1) {
            return PosixError::Create(errno,
                                      "fseek(%lld, %d): %s",
                                      offset,
                                      whence,
                                      path_.ToString().c_str());
        }

        return Ok(None());
    }
#endif

#if RHETORIC_MACOS
    Result<int64_t> FileStream::GetPosition() {
        RHETORIC_ASSERT(!closed());

        long pos = ftell(handle_);
        if (pos == -1) {
            return PosixError::Create(errno,
                                      "ftell: %s",
                                      path_.ToString().c_str());
        }

        return Ok(pos);
    }
#endif

    Result<Ptr<FileStream>> FileStream::Open(const FilePath & path,
                                             const std::string & mode)
    {
        std::string path_str = path.ToString();
        
        FILE * handle;
        auto err = _fopen(&handle, path_str.c_str(), mode.c_str());
        if (err) {
            return PosixError::Create(err,
                                      "fopen(%s, %s)",
                                      path_str.c_str(),
                                      mode.c_str());
        }
        return Ok(Ptr<FileStream>(new FileStream(handle, path)));
    }

    FileStream::FileStream(FILE * handle,
                           const FilePath & path):
    handle_(handle),
    path_(path)
    {}
}

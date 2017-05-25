#include "./posix_error.h"

namespace rhetoric {
    PosixError::PosixError(int code, const std::string & message):
    code_(code),
    message_(message)
    {}

    std::string PosixError::ToString() const {
        return Format("PosixError(%s(%d), %s)",
                      GetPosixErrorString(code_).c_str(),
                      code_,
                      message_.c_str());
    }

    int PosixError::code() const {
        return code_;
    }

    std::string PosixError::message() const {
        return message_;
    }

    Ptr<PosixError> PosixError::Create(int code, const char * format, ...) {
        va_list args;
        va_start(args, format);
        auto message = FormatV(format, args);
        va_end(args);
        return New<PosixError>(code, message);
    }

    std::string GetPosixErrorString(int code) {
		return std::string(strerror(code));
    }
}

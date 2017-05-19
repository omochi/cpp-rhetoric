#include "./generic_error.h"

namespace rhetoric {
    GenericError::GenericError(const std::string & message):
    message_(message)
    {}

    std::string GenericError::ToString() const {
        return Format("GenericError(%s)", message_.c_str());
    }

    std::string GenericError::message() const {
        return message_;
    }

    Ptr<GenericError>
    GenericError::Create(const char * format, ...) {
        va_list args;
        va_start(args, format);
        auto message = FormatV(format, args);
        va_end(args);
        return New<GenericError>(message);
    }
    
}

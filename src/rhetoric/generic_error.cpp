#include "./generic_error.h"

namespace rhetoric {
    GenericError::GenericError(const std::string & message,
                               const Ptr<Error> & causer):
    message_(message),
    causer_(causer)
    {}

    std::string GenericError::ToString() const {
        std::vector<std::string> lines;

        lines.push_back(Format("GenericError(%s)", message_.c_str()));
        if (causer_) {
            lines.push_back(Format("caused by %s", causer_->ToString().c_str()));
        }

        return Join(lines, "\n");
    }

    std::string GenericError::message() const {
        return message_;
    }

    Ptr<Error> GenericError::causer() const {
        return causer_;
    }

    Ptr<GenericError>
    GenericError::Create(const char * format, ...) {
        va_list args;
        va_start(args, format);
        auto message = FormatV(format, args);
        va_end(args);
        return New<GenericError>(message);
    }

    Ptr<GenericError>
    GenericError::Create(const Ptr<Error> & causer,
           const char * format, ...)
    {
        RHETORIC_ASSERT(causer != nullptr);
        
        va_list args;
        va_start(args, format);
        auto message = FormatV(format, args);
        va_end(args);
        return New<GenericError>(message, causer);
    }

}

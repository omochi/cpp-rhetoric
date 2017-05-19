#pragma once


#include "./attribute.h"
#include "./error.h"
#include "./format.h"
#include "./std_dependency.h"
#include "./ptr.h"

namespace rhetoric {
    class GenericError : public Error {
    public:
        GenericError(const std::string & message);
        virtual std::string ToString() const override;

        std::string message() const;

        static Ptr<GenericError>
        Create(const char * format, ...) RHETORIC_PRINTF_LIKE(1, 2);
    private:
        std::string message_;
    };
}


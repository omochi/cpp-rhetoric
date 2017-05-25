#pragma once


#include "./attribute.h"
#include "./error.h"
#include "./format.h"
#include "./std_dependency.h"
#include "./string_function.h"
#include "./ptr.h"

namespace rhetoric {
    class GenericError : public Error {
    public:
        GenericError(const std::string & message,
                     const Ptr<Error> & causer = nullptr);

        virtual std::string ToString() const override;

        std::string message() const;
        Ptr<Error> causer() const;

        static Ptr<GenericError>
        Create(RHETORIC_PRINTF_FORMAT_ARG, ...) RHETORIC_PRINTF_LIKE(1, 2);

        static Ptr<GenericError>
        Create(const Ptr<Error> & causer,
			RHETORIC_PRINTF_FORMAT_ARG, ...) RHETORIC_PRINTF_LIKE(2, 3);
    private:
        std::string message_;
        Ptr<Error> causer_;
    };
}


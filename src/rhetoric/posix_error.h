#pragma once

#include "./assert.h"
#include "./attribute.h"
#include "./defer.h"
#include "./error.h"
#include "./format.h"
#include "./ptr.h"
#include "./string_windows.h"
#include "./windows_dependency.h"

namespace rhetoric {
    class PosixError : public Error {
    public:
        PosixError(int code, const std::string & message);
        virtual std::string ToString() const override;

        int code() const;
        std::string message() const;

        static Ptr<PosixError>
        Create(int code, RHETORIC_PRINTF_FORMAT_ARG, ...) RHETORIC_PRINTF_LIKE(2, 3);
    private:
        int code_;
        std::string message_;
    };

    std::string GetPosixErrorString(int code);
}

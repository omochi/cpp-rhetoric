#pragma once

#include "./assert.h"
#include "./attribute.h"
#include "./error.h"
#include "./optional.h"
#include "./ptr.h"

namespace rhetoric {
    struct ResultSuccessTag {};

    struct ResultFailure {
        Ptr<Error> error;
    };

    template <typename T>
    class Result {
    public:
        Result();
        Result(const T & value, ResultSuccessTag tag);
        Result(const ResultFailure & failure);

        Result(const Result<T> & other);
        Result<T> & operator=(const Result<T> & other);

        template <typename U>
        Result(const Result<U> & other,
               typename std::enable_if<std::is_convertible<U, T>::value>::type * enabler = nullptr);
        
        ~Result();

        bool succeeded() const;
        explicit operator bool() const;

        const T & value() const;
        const Ptr<Error> & error() const;

        const T * operator->() const;
        const T & operator*() const;

        T Recover(const T & recovery_value) const;

    private:
        Optional<T> value_;
        Ptr<Error> error_;
    };

    template <typename T>
    Result<T> Success(const T & value);

    ResultFailure Failure(const Ptr<Error> & error);

    template <typename T>
    ResultFailure Failure(const Result<T> & result);
}

#include "./result_inline.h"





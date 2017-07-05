#pragma once

#include "./assert.h"
#include "./attribute.h"
#include "./either.h"
#include "./error.h"
#include "./optional.h"
#include "./ptr.h"

namespace rhetoric {
    struct ResultFailure {
        Ptr<Error> error;
    };

    constexpr Either2Tag FailureTag = Either2Tag::Case0;
    constexpr Either2Tag SuccessTag = Either2Tag::Case1;
    
    template <typename T>
    class Result {
    public:
        using ValueType = T;

        Result();
        /* implicit */ Result(const ResultFailure & failure);
        explicit Result(const Either2CaseWrapper<SuccessTag, T> & value);

        Result(const Result<T> & other);
        Result<T> & operator=(const Result<T> & other);

        template <typename U>
        Result(const Result<U> & other,
               std::enable_if_t<std::is_convertible<U, T>::value> * = nullptr);
        
        ~Result();

        bool succeeded() const;
        explicit operator bool() const;

        const T & value() const;
        const Ptr<Error> & error() const;

        const T * operator->() const;
        const T & operator*() const;

        T Recover(const T & recovery_value) const;

    private:
        Either2<Ptr<Error>, T> either_;
    };

    template <typename T>
    Result<T> Success(const T & value);

    ResultFailure Failure(const Ptr<Error> & error);

    template <typename T>
    ResultFailure Failure(const Result<T> & result);
}

#include "./result_inline.h"





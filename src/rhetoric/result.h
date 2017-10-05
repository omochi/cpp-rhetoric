#pragma once

#include "./assert.h"
#include "./attribute.h"
#include "./either.h"
#include "./error.h"
#include "./fatal.h"
#include "./option.h"
#include "./ptr.h"

namespace rhetoric {
    template <typename T> class Result;

    constexpr Either2Tag ErrorTag = Either2Tag::Case0;
    constexpr Either2Tag OkTag = Either2Tag::Case1;
    
    template <typename T>
    class Result {
    public:
        using ValueType = T;

        Result();
        /* implicit */ Result(const Ptr<Error> & error);
        
        template <typename E>
        /* implicit */ Result(const E & error,
                              std::enable_if_t<std::is_convertible<E, Ptr<Error>>::value> * = nullptr);
        
        explicit Result(const Either2CaseWrapper<OkTag, T> & value);

        Result(const Result<T> & other);
        Result<T> & operator=(const Result<T> & other);

        template <typename U>
        Result(const Result<U> & other,
               std::enable_if_t<std::is_convertible<U, T>::value> * = nullptr);
        
        ~Result();

        bool ok() const;
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
    Result<T> Ok(const T & value);
}

#include "./result_inline.h"





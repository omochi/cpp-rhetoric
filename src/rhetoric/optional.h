#pragma once

#include "./assert.h"
#include "./attribute.h"
#include "./either.h"
#include "./equatable_macro.h"
#include "./none.h"
#include "./std_dependency.h"

namespace rhetoric {
    struct OptionalSomeTag {};

    template <typename T>
    class Optional {
    public:
        using ValueType = T;
        
        Optional();
        Optional(const None &);
        Optional(const T & value, OptionalSomeTag);
        Optional(const Optional<T> & other);
        Optional<T> & operator=(const Optional<T> & other);

        template <typename U>
        Optional(const Optional<U> & other,
                 typename std::enable_if<std::is_convertible<U, T>::value>::type * = nullptr);

        ~Optional();

        bool presented() const;
        explicit operator bool() const;

        const T & value() const;

        const T * operator->() const;
        const T & operator*() const;

        bool operator==(const Optional<T> & other) const;
        RHETORIC_EQUATABLE_DEFAULT(Optional<T>);

        T GetOr(const T & default_value) const;
    private:
        Either2<None, T> either_;
    };

    template <typename T>
    Optional<T> Some(const T & value);
}

#include "./optional_inline.h"

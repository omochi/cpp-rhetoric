#pragma once

#include "./std_dependency.h"

#include "./assert.h"
#include "./attribute.h"
#include "./either.h"
#include "./equatable_macro.h"
#include "./none.h"

namespace rhetoric {
    
    constexpr Either2Tag NoneTag = Either2Tag::Case0;
    constexpr Either2Tag SomeTag = Either2Tag::Case1;
    
    template <typename T>
    class Optional {
    public:
        using ValueType = T;
        
        Optional();
        /* implicit */ Optional(const None &);
        explicit Optional(const Either2CaseWrapper<SomeTag, T> & value);
        
        Optional(const Optional<T> & other);
        Optional<T> & operator=(const Optional<T> & other);

        template <typename U>
        Optional(const Optional<U> & other,
                 typename std::enable_if_t<std::is_convertible<U, T>::value> * = nullptr);

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

#pragma once

#include "./std_dependency.h"

#include "./assert.h"
#include "./attribute.h"
#include "./concept_macro.h"
#include "./either.h"
#include "./none.h"

namespace rhetoric {
    
    constexpr Either2Tag NoneTag = Either2Tag::Case0;
    constexpr Either2Tag SomeTag = Either2Tag::Case1;
    
    template <typename T>
    class Option {
    public:
        using ValueType = T;
        
        Option();
        /* implicit */ Option(const None &);
        explicit Option(const Either2CaseWrapper<SomeTag, T> & value);
        
        Option(const Option<T> & other);
        Option<T> & operator=(const Option<T> & other);

        template <typename U>
        Option(const Option<U> & other,
                 typename std::enable_if_t<std::is_convertible<U, T>::value> * = nullptr);

        ~Option();

        bool presented() const;
        explicit operator bool() const;

        const T & value() const;

        const T * operator->() const;
        const T & operator*() const;

        bool operator==(const Option<T> & other) const;
        RHETORIC_EQUATABLE_DEFAULT(Option<T>);

        T GetOr(const T & default_value) const;
    private:
        Either2<None, T> either_;
    };

    template <typename T>
    Option<T> Some(const T & value);
}

#include "./option_inline.h"

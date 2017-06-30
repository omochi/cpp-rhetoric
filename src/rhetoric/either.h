#pragma once

#include "./assert.h"
#include "./fatal.h"
#include "./std_dependency.h"

namespace rhetoric {
    template <typename T> class EitherCase0Wrapper;
    template <typename T> class EitherCase1Wrapper;
    
    template <typename T>
    EitherCase0Wrapper<T> EitherCase0(const T & value);

    template <typename T>
    EitherCase1Wrapper<T> EitherCase1(const T & value);
    
    template <typename T0, typename T1>
    class Either2 {
    public:
        enum class Tag : int8_t {
            Case0,
            Case1
        };
        
        Either2() = delete;
        /* implicit */ Either2(const EitherCase0Wrapper<T0> & value);
        /* implicit */ Either2(const EitherCase1Wrapper<T1> & value);
        Either2(const Either2<T0, T1> & other);
        template <typename U0, typename U1>
        Either2(const Either2<U0, U1> & other,
                typename std::enable_if<
                    std::is_convertible<U0, T0>::value &&
                    std::is_convertible<U1, T1>::value
                >::type * = nullptr);
        Either2<T0, T1> & operator= (const Either2<T0, T1> & other);
        ~Either2();
        
        Tag tag() const;
        const T0 & AsCase0() const;
        const T1 & AsCase1() const;
    private:
        union Storage {
            T0 value0;
            T1 value1;
            
            Storage();
            ~Storage();
        };
        
        void InitValue0(const T0 & value);
        void InitValue1(const T1 & value);
        void Deinit();
        
        Storage storage_;
        Tag tag_;
    };
    
    template <typename T>
    struct EitherCase0Wrapper {
        T value;
        EitherCase0Wrapper(const T & value);
    };
    
    template <typename T>
    struct EitherCase1Wrapper {
        T value;
        EitherCase1Wrapper(const T & value);
    };
    
}

#include "./either_inline.h"

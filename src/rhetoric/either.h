#pragma once

#include "./assert.h"
#include "./fatal.h"
#include "./std_dependency.h"

namespace rhetoric {
    template <int C, typename T> class EitherCaseWrapper;
    
    template <int C, typename T>
    EitherCaseWrapper<C, T> EitherCase(const T & value);
    
    template <typename T0, typename T1>
    class Either2 {
    public:
        enum class Tag : int8_t {
            Case0,
            Case1
        };
        
        Either2() = delete;
        /* implicit */ Either2(const EitherCaseWrapper<0, T0> & value);
        /* implicit */ Either2(const EitherCaseWrapper<1, T1> & value);
        Either2(const Either2<T0, T1> & other);
        template <typename U0, typename U1>
        Either2(
        	const Either2<U0, U1> & other,
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

    template <typename T0, typename T1, typename T2>
    class Either3 {
    public:
        enum class Tag : int8_t {
            Case0,
            Case1,
            Case2
        };
        
        Either3() = delete;
        /* implicit */ Either3(const EitherCaseWrapper<0, T0> & value);
        /* implicit */ Either3(const EitherCaseWrapper<1, T1> & value);
        /* implicit */ Either3(const EitherCaseWrapper<2, T2> & value);
        Either3(const Either3<T0, T1, T2> & other);
        template <typename U0, typename U1, typename U2>
        Either3(
        	const Either3<U0, U1, U2> & other,
            typename std::enable_if<
                std::is_convertible<U0, T0>::value &&
                std::is_convertible<U1, T1>::value &&
                std::is_convertible<U2, T2>::value
            >::type * = nullptr);
        Either3<T0, T1, T2> & operator= (const Either3<T0, T1, T2> & other);
        ~Either3();
        
        Tag tag() const;
        const T0 & AsCase0() const;
        const T1 & AsCase1() const;
        const T2 & AsCase2() const;
    private:
        union Storage {
            T0 value0;
            T1 value1;
            T2 value2;

            Storage();
            ~Storage();
        };

        void InitValue0(const T0 & value);
        void InitValue1(const T1 & value);
        void InitValue2(const T2 & value);
        void Deinit();
        
        Storage storage_;
        Tag tag_;
    };

    template <typename T0, typename T1, typename T2, typename T3>
    class Either4 {
    public:
        enum class Tag : int8_t {
            Case0,
            Case1,
            Case2,
            Case3
        };
        
        Either4() = delete;
        /* implicit */ Either4(const EitherCaseWrapper<0, T0> & value);
        /* implicit */ Either4(const EitherCaseWrapper<1, T1> & value);
        /* implicit */ Either4(const EitherCaseWrapper<2, T2> & value);
        /* implicit */ Either4(const EitherCaseWrapper<3, T3> & value);
        Either4(const Either4<T0, T1, T2, T3> & other);
        template <typename U0, typename U1, typename U2, typename U3>
        Either4(
        	const Either4<U0, U1, U2, U3> & other,
            typename std::enable_if<
                std::is_convertible<U0, T0>::value &&
                std::is_convertible<U1, T1>::value &&
                std::is_convertible<U2, T2>::value &&
                std::is_convertible<U3, T3>::value
            >::type * = nullptr);
        Either4<T0, T1, T2, T3> & operator= (const Either4<T0, T1, T2, T3> & other);
        ~Either4();
        
        Tag tag() const;
        const T0 & AsCase0() const;
        const T1 & AsCase1() const;
        const T2 & AsCase2() const;
        const T3 & AsCase3() const;
    private:
        union Storage {
            T0 value0;
            T1 value1;
            T2 value2;
            T3 value3;

            Storage();
            ~Storage();
        };

        void InitValue0(const T0 & value);
        void InitValue1(const T1 & value);
        void InitValue2(const T2 & value);
        void InitValue3(const T3 & value);
        void Deinit();
        
        Storage storage_;
        Tag tag_;
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    class Either5 {
    public:
        enum class Tag : int8_t {
            Case0,
            Case1,
            Case2,
            Case3,
            Case4
        };
        
        Either5() = delete;
        /* implicit */ Either5(const EitherCaseWrapper<0, T0> & value);
        /* implicit */ Either5(const EitherCaseWrapper<1, T1> & value);
        /* implicit */ Either5(const EitherCaseWrapper<2, T2> & value);
        /* implicit */ Either5(const EitherCaseWrapper<3, T3> & value);
        /* implicit */ Either5(const EitherCaseWrapper<4, T4> & value);
        Either5(const Either5<T0, T1, T2, T3, T4> & other);
        template <typename U0, typename U1, typename U2, typename U3, typename U4>
        Either5(
        	const Either5<U0, U1, U2, U3, U4> & other,
            typename std::enable_if<
                std::is_convertible<U0, T0>::value &&
                std::is_convertible<U1, T1>::value &&
                std::is_convertible<U2, T2>::value &&
                std::is_convertible<U3, T3>::value &&
                std::is_convertible<U4, T4>::value
            >::type * = nullptr);
        Either5<T0, T1, T2, T3, T4> & operator= (const Either5<T0, T1, T2, T3, T4> & other);
        ~Either5();
        
        Tag tag() const;
        const T0 & AsCase0() const;
        const T1 & AsCase1() const;
        const T2 & AsCase2() const;
        const T3 & AsCase3() const;
        const T4 & AsCase4() const;
    private:
        union Storage {
            T0 value0;
            T1 value1;
            T2 value2;
            T3 value3;
            T4 value4;

            Storage();
            ~Storage();
        };

        void InitValue0(const T0 & value);
        void InitValue1(const T1 & value);
        void InitValue2(const T2 & value);
        void InitValue3(const T3 & value);
        void InitValue4(const T4 & value);
        void Deinit();
        
        Storage storage_;
        Tag tag_;
    };

    template <int C, typename T>
    struct EitherCaseWrapper {
        T value;
        EitherCaseWrapper(const T & value);
    };
    
}

#include "./either_inline.h"

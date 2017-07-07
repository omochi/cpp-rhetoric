#pragma once

#include "./assert.h"
#include "./fatal.h"
#include "./std_dependency.h"

namespace rhetoric {
    enum class Either2Tag : int8_t {
        Case0 = 0,
        Case1 = 1
    };

    template <Either2Tag G, typename T> struct Either2CaseWrapper;

    template <Either2Tag G, typename T>
    Either2CaseWrapper<G, T> EitherCase(const T & value);

    template <typename T0, typename T1>
    class Either2 {
    public:
        Either2() = delete;
        /* implicit */ Either2(const Either2CaseWrapper<Either2Tag::Case0, T0> & value);
        /* implicit */ Either2(const Either2CaseWrapper<Either2Tag::Case1, T1> & value);
        Either2(const Either2<T0, T1> & other);
        template <typename U0, typename U1>
        Either2(
        	const Either2<U0, U1> & other,
            std::enable_if_t<
                std::is_convertible<U0, T0>::value &&
                std::is_convertible<U1, T1>::value
            > * = nullptr);
        Either2<T0, T1> & operator= (const Either2<T0, T1> & other);
        ~Either2();
        
        Either2Tag tag() const;
        const T0 & AsCase0() const;
        const T1 & AsCase1() const;

        template <Either2Tag G>
        const T0 & AsCase(std::enable_if_t<  G == Either2Tag::Case0  > * = nullptr) const 
        { return AsCase0(); }
        
        template <Either2Tag G>
        const T1 & AsCase(std::enable_if_t<  G == Either2Tag::Case1  > * = nullptr) const 
        { return AsCase1(); }
        
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
        Either2Tag tag_;
    };

    template <Either2Tag G, typename T>
    struct Either2CaseWrapper {
        T value;
        Either2CaseWrapper(const T & value);
    };

    enum class Either3Tag : int8_t {
        Case0 = 0,
        Case1 = 1,
        Case2 = 2
    };

    template <Either3Tag G, typename T> struct Either3CaseWrapper;

    template <Either3Tag G, typename T>
    Either3CaseWrapper<G, T> EitherCase(const T & value);

    template <typename T0, typename T1, typename T2>
    class Either3 {
    public:
        Either3() = delete;
        /* implicit */ Either3(const Either3CaseWrapper<Either3Tag::Case0, T0> & value);
        /* implicit */ Either3(const Either3CaseWrapper<Either3Tag::Case1, T1> & value);
        /* implicit */ Either3(const Either3CaseWrapper<Either3Tag::Case2, T2> & value);
        Either3(const Either3<T0, T1, T2> & other);
        template <typename U0, typename U1, typename U2>
        Either3(
        	const Either3<U0, U1, U2> & other,
            std::enable_if_t<
                std::is_convertible<U0, T0>::value &&
                std::is_convertible<U1, T1>::value &&
                std::is_convertible<U2, T2>::value
            > * = nullptr);
        Either3<T0, T1, T2> & operator= (const Either3<T0, T1, T2> & other);
        ~Either3();
        
        Either3Tag tag() const;
        const T0 & AsCase0() const;
        const T1 & AsCase1() const;
        const T2 & AsCase2() const;

        template <Either3Tag G>
        const T0 & AsCase(std::enable_if_t<  G == Either3Tag::Case0  > * = nullptr) const 
        { return AsCase0(); }
        
        template <Either3Tag G>
        const T1 & AsCase(std::enable_if_t<  G == Either3Tag::Case1  > * = nullptr) const 
        { return AsCase1(); }
        
        template <Either3Tag G>
        const T2 & AsCase(std::enable_if_t<  G == Either3Tag::Case2  > * = nullptr) const 
        { return AsCase2(); }
        
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
        Either3Tag tag_;
    };

    template <Either3Tag G, typename T>
    struct Either3CaseWrapper {
        T value;
        Either3CaseWrapper(const T & value);
    };

    enum class Either4Tag : int8_t {
        Case0 = 0,
        Case1 = 1,
        Case2 = 2,
        Case3 = 3
    };

    template <Either4Tag G, typename T> struct Either4CaseWrapper;

    template <Either4Tag G, typename T>
    Either4CaseWrapper<G, T> EitherCase(const T & value);

    template <typename T0, typename T1, typename T2, typename T3>
    class Either4 {
    public:
        Either4() = delete;
        /* implicit */ Either4(const Either4CaseWrapper<Either4Tag::Case0, T0> & value);
        /* implicit */ Either4(const Either4CaseWrapper<Either4Tag::Case1, T1> & value);
        /* implicit */ Either4(const Either4CaseWrapper<Either4Tag::Case2, T2> & value);
        /* implicit */ Either4(const Either4CaseWrapper<Either4Tag::Case3, T3> & value);
        Either4(const Either4<T0, T1, T2, T3> & other);
        template <typename U0, typename U1, typename U2, typename U3>
        Either4(
        	const Either4<U0, U1, U2, U3> & other,
            std::enable_if_t<
                std::is_convertible<U0, T0>::value &&
                std::is_convertible<U1, T1>::value &&
                std::is_convertible<U2, T2>::value &&
                std::is_convertible<U3, T3>::value
            > * = nullptr);
        Either4<T0, T1, T2, T3> & operator= (const Either4<T0, T1, T2, T3> & other);
        ~Either4();
        
        Either4Tag tag() const;
        const T0 & AsCase0() const;
        const T1 & AsCase1() const;
        const T2 & AsCase2() const;
        const T3 & AsCase3() const;

        template <Either4Tag G>
        const T0 & AsCase(std::enable_if_t<  G == Either4Tag::Case0  > * = nullptr) const 
        { return AsCase0(); }
        
        template <Either4Tag G>
        const T1 & AsCase(std::enable_if_t<  G == Either4Tag::Case1  > * = nullptr) const 
        { return AsCase1(); }
        
        template <Either4Tag G>
        const T2 & AsCase(std::enable_if_t<  G == Either4Tag::Case2  > * = nullptr) const 
        { return AsCase2(); }
        
        template <Either4Tag G>
        const T3 & AsCase(std::enable_if_t<  G == Either4Tag::Case3  > * = nullptr) const 
        { return AsCase3(); }
        
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
        Either4Tag tag_;
    };

    template <Either4Tag G, typename T>
    struct Either4CaseWrapper {
        T value;
        Either4CaseWrapper(const T & value);
    };

    enum class Either5Tag : int8_t {
        Case0 = 0,
        Case1 = 1,
        Case2 = 2,
        Case3 = 3,
        Case4 = 4
    };

    template <Either5Tag G, typename T> struct Either5CaseWrapper;

    template <Either5Tag G, typename T>
    Either5CaseWrapper<G, T> EitherCase(const T & value);

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    class Either5 {
    public:
        Either5() = delete;
        /* implicit */ Either5(const Either5CaseWrapper<Either5Tag::Case0, T0> & value);
        /* implicit */ Either5(const Either5CaseWrapper<Either5Tag::Case1, T1> & value);
        /* implicit */ Either5(const Either5CaseWrapper<Either5Tag::Case2, T2> & value);
        /* implicit */ Either5(const Either5CaseWrapper<Either5Tag::Case3, T3> & value);
        /* implicit */ Either5(const Either5CaseWrapper<Either5Tag::Case4, T4> & value);
        Either5(const Either5<T0, T1, T2, T3, T4> & other);
        template <typename U0, typename U1, typename U2, typename U3, typename U4>
        Either5(
        	const Either5<U0, U1, U2, U3, U4> & other,
            std::enable_if_t<
                std::is_convertible<U0, T0>::value &&
                std::is_convertible<U1, T1>::value &&
                std::is_convertible<U2, T2>::value &&
                std::is_convertible<U3, T3>::value &&
                std::is_convertible<U4, T4>::value
            > * = nullptr);
        Either5<T0, T1, T2, T3, T4> & operator= (const Either5<T0, T1, T2, T3, T4> & other);
        ~Either5();
        
        Either5Tag tag() const;
        const T0 & AsCase0() const;
        const T1 & AsCase1() const;
        const T2 & AsCase2() const;
        const T3 & AsCase3() const;
        const T4 & AsCase4() const;

        template <Either5Tag G>
        const T0 & AsCase(std::enable_if_t<  G == Either5Tag::Case0  > * = nullptr) const 
        { return AsCase0(); }
        
        template <Either5Tag G>
        const T1 & AsCase(std::enable_if_t<  G == Either5Tag::Case1  > * = nullptr) const 
        { return AsCase1(); }
        
        template <Either5Tag G>
        const T2 & AsCase(std::enable_if_t<  G == Either5Tag::Case2  > * = nullptr) const 
        { return AsCase2(); }
        
        template <Either5Tag G>
        const T3 & AsCase(std::enable_if_t<  G == Either5Tag::Case3  > * = nullptr) const 
        { return AsCase3(); }
        
        template <Either5Tag G>
        const T4 & AsCase(std::enable_if_t<  G == Either5Tag::Case4  > * = nullptr) const 
        { return AsCase4(); }
        
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
        Either5Tag tag_;
    };

    template <Either5Tag G, typename T>
    struct Either5CaseWrapper {
        T value;
        Either5CaseWrapper(const T & value);
    };

    enum class Either6Tag : int8_t {
        Case0 = 0,
        Case1 = 1,
        Case2 = 2,
        Case3 = 3,
        Case4 = 4,
        Case5 = 5
    };

    template <Either6Tag G, typename T> struct Either6CaseWrapper;

    template <Either6Tag G, typename T>
    Either6CaseWrapper<G, T> EitherCase(const T & value);

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    class Either6 {
    public:
        Either6() = delete;
        /* implicit */ Either6(const Either6CaseWrapper<Either6Tag::Case0, T0> & value);
        /* implicit */ Either6(const Either6CaseWrapper<Either6Tag::Case1, T1> & value);
        /* implicit */ Either6(const Either6CaseWrapper<Either6Tag::Case2, T2> & value);
        /* implicit */ Either6(const Either6CaseWrapper<Either6Tag::Case3, T3> & value);
        /* implicit */ Either6(const Either6CaseWrapper<Either6Tag::Case4, T4> & value);
        /* implicit */ Either6(const Either6CaseWrapper<Either6Tag::Case5, T5> & value);
        Either6(const Either6<T0, T1, T2, T3, T4, T5> & other);
        template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5>
        Either6(
        	const Either6<U0, U1, U2, U3, U4, U5> & other,
            std::enable_if_t<
                std::is_convertible<U0, T0>::value &&
                std::is_convertible<U1, T1>::value &&
                std::is_convertible<U2, T2>::value &&
                std::is_convertible<U3, T3>::value &&
                std::is_convertible<U4, T4>::value &&
                std::is_convertible<U5, T5>::value
            > * = nullptr);
        Either6<T0, T1, T2, T3, T4, T5> & operator= (const Either6<T0, T1, T2, T3, T4, T5> & other);
        ~Either6();
        
        Either6Tag tag() const;
        const T0 & AsCase0() const;
        const T1 & AsCase1() const;
        const T2 & AsCase2() const;
        const T3 & AsCase3() const;
        const T4 & AsCase4() const;
        const T5 & AsCase5() const;

        template <Either6Tag G>
        const T0 & AsCase(std::enable_if_t<  G == Either6Tag::Case0  > * = nullptr) const 
        { return AsCase0(); }
        
        template <Either6Tag G>
        const T1 & AsCase(std::enable_if_t<  G == Either6Tag::Case1  > * = nullptr) const 
        { return AsCase1(); }
        
        template <Either6Tag G>
        const T2 & AsCase(std::enable_if_t<  G == Either6Tag::Case2  > * = nullptr) const 
        { return AsCase2(); }
        
        template <Either6Tag G>
        const T3 & AsCase(std::enable_if_t<  G == Either6Tag::Case3  > * = nullptr) const 
        { return AsCase3(); }
        
        template <Either6Tag G>
        const T4 & AsCase(std::enable_if_t<  G == Either6Tag::Case4  > * = nullptr) const 
        { return AsCase4(); }
        
        template <Either6Tag G>
        const T5 & AsCase(std::enable_if_t<  G == Either6Tag::Case5  > * = nullptr) const 
        { return AsCase5(); }
        
    private:
        union Storage {
            T0 value0;
            T1 value1;
            T2 value2;
            T3 value3;
            T4 value4;
            T5 value5;

            Storage();
            ~Storage();
        };

        void InitValue0(const T0 & value);
        void InitValue1(const T1 & value);
        void InitValue2(const T2 & value);
        void InitValue3(const T3 & value);
        void InitValue4(const T4 & value);
        void InitValue5(const T5 & value);
        void Deinit();
        
        Storage storage_;
        Either6Tag tag_;
    };

    template <Either6Tag G, typename T>
    struct Either6CaseWrapper {
        T value;
        Either6CaseWrapper(const T & value);
    };

    enum class Either7Tag : int8_t {
        Case0 = 0,
        Case1 = 1,
        Case2 = 2,
        Case3 = 3,
        Case4 = 4,
        Case5 = 5,
        Case6 = 6
    };

    template <Either7Tag G, typename T> struct Either7CaseWrapper;

    template <Either7Tag G, typename T>
    Either7CaseWrapper<G, T> EitherCase(const T & value);

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    class Either7 {
    public:
        Either7() = delete;
        /* implicit */ Either7(const Either7CaseWrapper<Either7Tag::Case0, T0> & value);
        /* implicit */ Either7(const Either7CaseWrapper<Either7Tag::Case1, T1> & value);
        /* implicit */ Either7(const Either7CaseWrapper<Either7Tag::Case2, T2> & value);
        /* implicit */ Either7(const Either7CaseWrapper<Either7Tag::Case3, T3> & value);
        /* implicit */ Either7(const Either7CaseWrapper<Either7Tag::Case4, T4> & value);
        /* implicit */ Either7(const Either7CaseWrapper<Either7Tag::Case5, T5> & value);
        /* implicit */ Either7(const Either7CaseWrapper<Either7Tag::Case6, T6> & value);
        Either7(const Either7<T0, T1, T2, T3, T4, T5, T6> & other);
        template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6>
        Either7(
        	const Either7<U0, U1, U2, U3, U4, U5, U6> & other,
            std::enable_if_t<
                std::is_convertible<U0, T0>::value &&
                std::is_convertible<U1, T1>::value &&
                std::is_convertible<U2, T2>::value &&
                std::is_convertible<U3, T3>::value &&
                std::is_convertible<U4, T4>::value &&
                std::is_convertible<U5, T5>::value &&
                std::is_convertible<U6, T6>::value
            > * = nullptr);
        Either7<T0, T1, T2, T3, T4, T5, T6> & operator= (const Either7<T0, T1, T2, T3, T4, T5, T6> & other);
        ~Either7();
        
        Either7Tag tag() const;
        const T0 & AsCase0() const;
        const T1 & AsCase1() const;
        const T2 & AsCase2() const;
        const T3 & AsCase3() const;
        const T4 & AsCase4() const;
        const T5 & AsCase5() const;
        const T6 & AsCase6() const;

        template <Either7Tag G>
        const T0 & AsCase(std::enable_if_t<  G == Either7Tag::Case0  > * = nullptr) const 
        { return AsCase0(); }
        
        template <Either7Tag G>
        const T1 & AsCase(std::enable_if_t<  G == Either7Tag::Case1  > * = nullptr) const 
        { return AsCase1(); }
        
        template <Either7Tag G>
        const T2 & AsCase(std::enable_if_t<  G == Either7Tag::Case2  > * = nullptr) const 
        { return AsCase2(); }
        
        template <Either7Tag G>
        const T3 & AsCase(std::enable_if_t<  G == Either7Tag::Case3  > * = nullptr) const 
        { return AsCase3(); }
        
        template <Either7Tag G>
        const T4 & AsCase(std::enable_if_t<  G == Either7Tag::Case4  > * = nullptr) const 
        { return AsCase4(); }
        
        template <Either7Tag G>
        const T5 & AsCase(std::enable_if_t<  G == Either7Tag::Case5  > * = nullptr) const 
        { return AsCase5(); }
        
        template <Either7Tag G>
        const T6 & AsCase(std::enable_if_t<  G == Either7Tag::Case6  > * = nullptr) const 
        { return AsCase6(); }
        
    private:
        union Storage {
            T0 value0;
            T1 value1;
            T2 value2;
            T3 value3;
            T4 value4;
            T5 value5;
            T6 value6;

            Storage();
            ~Storage();
        };

        void InitValue0(const T0 & value);
        void InitValue1(const T1 & value);
        void InitValue2(const T2 & value);
        void InitValue3(const T3 & value);
        void InitValue4(const T4 & value);
        void InitValue5(const T5 & value);
        void InitValue6(const T6 & value);
        void Deinit();
        
        Storage storage_;
        Either7Tag tag_;
    };

    template <Either7Tag G, typename T>
    struct Either7CaseWrapper {
        T value;
        Either7CaseWrapper(const T & value);
    };

    enum class Either8Tag : int8_t {
        Case0 = 0,
        Case1 = 1,
        Case2 = 2,
        Case3 = 3,
        Case4 = 4,
        Case5 = 5,
        Case6 = 6,
        Case7 = 7
    };

    template <Either8Tag G, typename T> struct Either8CaseWrapper;

    template <Either8Tag G, typename T>
    Either8CaseWrapper<G, T> EitherCase(const T & value);

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    class Either8 {
    public:
        Either8() = delete;
        /* implicit */ Either8(const Either8CaseWrapper<Either8Tag::Case0, T0> & value);
        /* implicit */ Either8(const Either8CaseWrapper<Either8Tag::Case1, T1> & value);
        /* implicit */ Either8(const Either8CaseWrapper<Either8Tag::Case2, T2> & value);
        /* implicit */ Either8(const Either8CaseWrapper<Either8Tag::Case3, T3> & value);
        /* implicit */ Either8(const Either8CaseWrapper<Either8Tag::Case4, T4> & value);
        /* implicit */ Either8(const Either8CaseWrapper<Either8Tag::Case5, T5> & value);
        /* implicit */ Either8(const Either8CaseWrapper<Either8Tag::Case6, T6> & value);
        /* implicit */ Either8(const Either8CaseWrapper<Either8Tag::Case7, T7> & value);
        Either8(const Either8<T0, T1, T2, T3, T4, T5, T6, T7> & other);
        template <typename U0, typename U1, typename U2, typename U3, typename U4, typename U5, typename U6, typename U7>
        Either8(
        	const Either8<U0, U1, U2, U3, U4, U5, U6, U7> & other,
            std::enable_if_t<
                std::is_convertible<U0, T0>::value &&
                std::is_convertible<U1, T1>::value &&
                std::is_convertible<U2, T2>::value &&
                std::is_convertible<U3, T3>::value &&
                std::is_convertible<U4, T4>::value &&
                std::is_convertible<U5, T5>::value &&
                std::is_convertible<U6, T6>::value &&
                std::is_convertible<U7, T7>::value
            > * = nullptr);
        Either8<T0, T1, T2, T3, T4, T5, T6, T7> & operator= (const Either8<T0, T1, T2, T3, T4, T5, T6, T7> & other);
        ~Either8();
        
        Either8Tag tag() const;
        const T0 & AsCase0() const;
        const T1 & AsCase1() const;
        const T2 & AsCase2() const;
        const T3 & AsCase3() const;
        const T4 & AsCase4() const;
        const T5 & AsCase5() const;
        const T6 & AsCase6() const;
        const T7 & AsCase7() const;

        template <Either8Tag G>
        const T0 & AsCase(std::enable_if_t<  G == Either8Tag::Case0  > * = nullptr) const 
        { return AsCase0(); }
        
        template <Either8Tag G>
        const T1 & AsCase(std::enable_if_t<  G == Either8Tag::Case1  > * = nullptr) const 
        { return AsCase1(); }
        
        template <Either8Tag G>
        const T2 & AsCase(std::enable_if_t<  G == Either8Tag::Case2  > * = nullptr) const 
        { return AsCase2(); }
        
        template <Either8Tag G>
        const T3 & AsCase(std::enable_if_t<  G == Either8Tag::Case3  > * = nullptr) const 
        { return AsCase3(); }
        
        template <Either8Tag G>
        const T4 & AsCase(std::enable_if_t<  G == Either8Tag::Case4  > * = nullptr) const 
        { return AsCase4(); }
        
        template <Either8Tag G>
        const T5 & AsCase(std::enable_if_t<  G == Either8Tag::Case5  > * = nullptr) const 
        { return AsCase5(); }
        
        template <Either8Tag G>
        const T6 & AsCase(std::enable_if_t<  G == Either8Tag::Case6  > * = nullptr) const 
        { return AsCase6(); }
        
        template <Either8Tag G>
        const T7 & AsCase(std::enable_if_t<  G == Either8Tag::Case7  > * = nullptr) const 
        { return AsCase7(); }
        
    private:
        union Storage {
            T0 value0;
            T1 value1;
            T2 value2;
            T3 value3;
            T4 value4;
            T5 value5;
            T6 value6;
            T7 value7;

            Storage();
            ~Storage();
        };

        void InitValue0(const T0 & value);
        void InitValue1(const T1 & value);
        void InitValue2(const T2 & value);
        void InitValue3(const T3 & value);
        void InitValue4(const T4 & value);
        void InitValue5(const T5 & value);
        void InitValue6(const T6 & value);
        void InitValue7(const T7 & value);
        void Deinit();
        
        Storage storage_;
        Either8Tag tag_;
    };

    template <Either8Tag G, typename T>
    struct Either8CaseWrapper {
        T value;
        Either8CaseWrapper(const T & value);
    };

}

#include "./either_inline.h"

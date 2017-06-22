#pragma once

#include "./assert.h"
#include "./generic_error.h"
#include "./macro.h"
#include "./optional.h"
#include "./result.h"
#include "./std_dependency.h"

namespace rhetoric {
    template <typename A>
    bool
    ArrayCheckIndex(const A & array, int index);


    template <typename A>
    Result<typename A::value_type>
    ArrayGetAt(const A & array, int index);

    template <typename A>
    Optional<typename A::value_type>
    ArrayGetAtOrNone(const A & array, int index);

    template <typename A, typename P>
    Optional<typename A::value_type>
    ArrayFind(const A & array,
              P && pred);

    template <typename A>
    Optional<typename A::value_type>
    ArrayFindEq(const A & array,
                const typename A::value_type & item);

    template <typename A, typename P>
    Optional<typename A::value_type>
    ArrayFindR(const A & array,
               P && pred);

    template <typename A>
    Optional<typename A::value_type>
    ArrayFindEqR(const A & array,
                 const typename A::value_type & item);

    template <typename A, typename P>
    Optional<int>
    ArrayFindIndex(const A & array,
                   P && pred);

    template <typename A>
    Optional<int>
    ArrayFindIndexEq(const A & array,
                     const typename A::value_type & item);

    template <typename A, typename P>
    Optional<int>
    ArrayFindIndexR(const A & array,
                    P && pred);

    template <typename A>
    Optional<int>
    ArrayFindIndexEqR(const A & array,
                      const typename A::value_type & item);

    template <typename A, typename F>
    auto
    ArrayMap(const A & array,
             F && f)
    -> std::vector<  decltype(f(std::declval<  typename A::value_type  >()))  >;

    template <typename A, typename P>
    std::vector<typename A::value_type>
    ArrayFilter(const A & array,
                P && pred);
    
    template <typename A, typename F>
    auto
    ArrayFlatMap(const A & array,
                 F && f)
    -> std::vector<  typename RHETORIC_DECLTYPE(f(std::declval< typename A::value_type >()))::value_type  >;
    
    template <typename A, typename F>
    auto
    ArrayFlatMapOptional(const A & array,
                         F && f)
    -> std::vector<  typename RHETORIC_DECLTYPE(f(std::declval< typename A::value_type >()))::ValueType  >;

    template <typename A, typename P>
    void
    ArrayRemove(A * array,
                P && pred);

    template <typename A>
    void
    ArrayRemoveEq(A * array,
                  const typename A::value_type & item);

    template <typename A>
    void
    ArrayRemoveAt(A * array, int index);

    template <typename A, typename P>
    bool
    ArrayTestAll(const A & array,
                 P && pred);

    template <typename A, typename P>
    bool
    ArrayTestAny(const A & array,
                 P && pred);

    template <typename A, typename P>
    int
    ArrayCount(const A & array,
               P && pred);

    template <typename A>
    void
    ArrayReverse(A * array);

    template <typename A>
    std::vector<typename A::value_type>
    ArrayReversed(const A & array);
}

#include "./array_function_inline.h"

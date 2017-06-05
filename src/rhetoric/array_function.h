#pragma once

#include "./optional.h"
#include "./std_dependency.h"

namespace rhetoric {
    template <typename A, typename P>
    Optional<int>
    ArrayFind(const A & array,
              P && pred);

    template <typename A>
    Optional<int>
    ArrayFindEq(const A & array,
                const typename A::value_type & item);

    template <typename A, typename P>
    Optional<int>
    ArrayFindR(const A & array,
               P && pred);

    template <typename A>
    Optional<int>
    ArrayFindEqR(const A & array,
                 const typename A::value_type & item);

    template <typename A, typename F>
    auto
    ArrayMap(const A & array,
             F && f)
    -> std::vector<decltype(f(std::declval<typename A::value_type>()))>;

    template <typename A, typename P>
    std::vector<typename A::value_type>
    ArrayFilter(const A & array,
                P && pred);

    template <typename A, typename P>
    void
    ArrayRemove(A & array,
                P && pred);

    template <typename A>
    void
    ArrayRemoveEq(A & array,
                  const typename A::value_type & item);

    template <typename A>
    void
    ArrayRemoveAt(A & array, int index);

    template <typename A, typename P>
    bool
    ArrayTestAll(const A & array,
                 P && pred);

    template <typename A, typename P>
    bool
    ArrayTestAny(const A & array,
                 P && pred);

    template <typename A>
    void
    ArrayReverse(A & array);

    template <typename A>
    A
    ArrayReversed(const A & array);
}

#include "./array_function_inline.h"

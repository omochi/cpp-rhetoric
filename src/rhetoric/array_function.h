#pragma once

#include "./optional.h"
#include "./std_dependency.h"

namespace rhetoric {
    template <typename A, typename P>
    Optional<int>
    ArrayFind(const A & array,
              const P & pred);

    template <typename A, typename E>
    Optional<int>
    ArrayFindEq(const A & array,
                const E & item);

    template <typename A, typename P>
    Optional<int>
    ArrayFindR(const A & array,
               const P & pred);

    template <typename A, typename E>
    Optional<int>
    ArrayFindEqR(const A & array,
                 const E & item);

    template <typename A, typename P>
    void
    ArrayRemove(A & array,
                const P & pred);

    template <typename A, typename E>
    void
    ArrayRemoveEq(A & array,
                  const E & item);

    template <typename A>
    void
    ArrayRemoveAt(A & array, int index);

    template <typename A, typename P>
    bool
    ArrayTestAll(const A & array,
                 const P & pred);

    template <typename A, typename P>
    bool
    ArrayTestAny(const A & array,
                 const P & pred);

    template <typename A>
    void
    ArrayReverse(A & array);

    template <typename A>
    A
    ArrayReversed(const A & array);
}

#include "./array_function_inline.h"

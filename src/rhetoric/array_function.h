#pragma once

#include "./optional.h"
#include "./std_dependency.h"

namespace rhetoric {
    template <typename A, typename P>
    Optional<int>
    ArrayFind(const A & array,
              const P & pred);

    template <typename A, typename P>
    Optional<int>
    ArrayFindR(const A & array,
               const P & pred);

    template <typename A, typename P>
    void
    ArrayRemove(A & array,
                const P & pred);

    template <typename A>
    void
    ArrayRemoveAt(A & array, int index);

    template <typename A, typename P>
    bool
    TestAll(const A & array,
            const P & pred);

    template <typename A, typename P>
    bool
    TestAny(const A & array,
            const P & pred);
}

#include "./array_function_inline.h"

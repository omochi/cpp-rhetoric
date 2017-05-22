#pragma once

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
    ArrayRemove(C & array,
                const P & pred);

    template <typename C>
    void
    ArrayRemoveAt(C & array, int index);
}

#include "./array_function_inline.h"

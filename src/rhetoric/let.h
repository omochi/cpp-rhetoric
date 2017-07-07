#pragma once

#include "./std_dependency.h"

namespace rhetoric {
    template <typename T, typename F>
    auto
    Let(const T & obj,
        F && f) ->
    std::result_of_t<F(T)>
    {
        return f(obj);
    }
}

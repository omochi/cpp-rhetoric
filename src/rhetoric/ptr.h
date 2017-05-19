#pragma once

#include "./std_dependency.h"

namespace rhetoric {
    template <typename T> using Ptr = std::shared_ptr<T>;
    template <typename T> using WeakPtr = std::weak_ptr<T>;

    template <typename T, typename ...Args>
    Ptr<T> New(Args&&... args);
}

#include "./ptr_inline.h"


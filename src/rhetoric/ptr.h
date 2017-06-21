#pragma once

#include "./std_dependency.h"

#define RHETORIC_NEW(type, ...) (std::shared_ptr<type>(new type(__VA_ARGS__)))

namespace rhetoric {
    template <typename T> using Ptr = std::shared_ptr<T>;
    template <typename T> using WeakPtr = std::weak_ptr<T>;

    template <typename T, typename ...Args>
    Ptr<T> New(Args&&... args);
}

#include "./ptr_inline.h"


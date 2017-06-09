#pragma once

#include "./std_dependency.h"
#include "./macro.h"

#define RHETORIC_DEFER(proc) \
_RHETORIC_DEFER( RHETORIC_MACRO_CONCAT(rhetoric_defer_object_, __COUNTER__), proc)

namespace rhetoric {
    class Defer {
    public:
        Defer(const std::function<void()> proc);
        ~Defer();
    private:
        std::function<void()> proc_;
    };
}

#define _RHETORIC_DEFER(var, proc) \
rhetoric::Defer var = rhetoric::Defer(proc)

#define __RHETORIC_DEFER(counter, proc) \
auto __defer__ ## counter = rhetoric::Defer(proc)

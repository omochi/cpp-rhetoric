#pragma once

#include "./std_dependency.h"
#include "./macro.h"

#define RHETORIC_DEFER(proc) _RHETORIC_DEFER_1(__COUNTER__, proc)

namespace rhetoric {
    class Defer {
    public:
        Defer(const std::function<void()> proc);
        ~Defer();
    private:
        std::function<void()> proc_;
    };
}

#define _RHETORIC_DEFER_1(counter, proc) \
_RHETORIC_DEFER_2(rhetoric_defer_object_, counter, proc)

#define _RHETORIC_DEFER_2(var, counter, proc) \
rhetoric::Defer var ## counter = rhetoric::Defer(proc)



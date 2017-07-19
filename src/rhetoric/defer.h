#pragma once

#include "./std_dependency.h"

#define RHETORIC_DEFER(proc) _RHETORIC_DEFER_1(__COUNTER__, proc)

namespace rhetoric {
    class _Defer {
    public:
        _Defer(const std::function<void()> proc);
        ~_Defer();
    private:
        std::function<void()> proc_;
    };
}

#define _RHETORIC_DEFER_1(counter, proc) \
_RHETORIC_DEFER_2(rhetoric_defer_object_, counter, proc)

#define _RHETORIC_DEFER_2(var, counter, proc) \
rhetoric::_Defer var ## counter = rhetoric::_Defer(proc)



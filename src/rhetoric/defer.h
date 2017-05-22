#pragma once

#include "./std_dependency.h"

#define RHETORIC_DEFER(proc) \
_RHETORIC_DEFER(__COUNTER__, proc)

namespace rhetoric {
    class Defer {
    public:
        Defer(const std::function<void()> proc);
        ~Defer();
    private:
        std::function<void()> proc_;
    };
}

#define _RHETORIC_DEFER(counter, proc) \
__RHETORIC_DEFER(counter, proc)

#define __RHETORIC_DEFER(counter, proc) \
auto __defer__ ## counter = rhetoric::Defer(proc)

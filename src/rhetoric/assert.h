#pragma once

#include "./attribute.h"
#include "./fatal.h"
#include "./format.h"

#define RHETORIC_ASSERT(condition) \
rhetoric::Assert(condition, #condition, RHETORIC_PRETTY_FUNCTION, __FILE__, __LINE__)

namespace rhetoric {
    void Assert(bool condition,
                const char * condition_str,
                const char * func,
                const char * file,
                int line);
}

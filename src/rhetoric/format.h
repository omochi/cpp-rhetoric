#pragma once

#include "./attribute.h"
#include "./std_dependency.h"

namespace rhetoric {
    std::string Format(const char * format, ...) RHETORIC_PRINTF_LIKE(1, 2);
    std::string FormatV(const char * format, va_list args) RHETORIC_PRINTF_LIKE(1, 0);
}

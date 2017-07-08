#pragma once

#include "./std_dependency.h"

#include "./attribute.h"
#include "./signedness_convertion.h"

namespace rhetoric {
    std::string Format(RHETORIC_PRINTF_FORMAT_ARG, ...) RHETORIC_PRINTF_LIKE(1, 2);
    std::string FormatV(RHETORIC_PRINTF_FORMAT_ARG, va_list args) RHETORIC_PRINTF_LIKE(1, 0);
}

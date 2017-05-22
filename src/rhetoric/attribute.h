#pragma once

#include "./platform.h"

#if RHETORIC_MACOS
#   define RHETORIC_NO_RETURN [[noreturn]]
#   define RHETORIC_NO_DISCARD [[nodiscard]]
#   define RHETORIC_PRINTF_LIKE(f, a) __attribute__((__format__ (__printf__, f, a)))
#   define RHETORIC_UNUSED(x) (void)x
#endif

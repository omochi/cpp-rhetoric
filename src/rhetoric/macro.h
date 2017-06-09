#pragma once

#include "./platform.h"

#if RHETORIC_MACOS
#   define RHETORIC_PRETTY_FUNCTION __PRETTY_FUNCTION__
#endif

#if RHETORIC_WINDOWS
#   define RHETORIC_PRETTY_FUNCTION __FUNCSIG__
#endif

#define RHETORIC_MACRO_CONCAT(a, b) _RHETORIC_MACRO_CONCAT(a, b)

#define _RHETORIC_MACRO_CONCAT(a, b) a ## b

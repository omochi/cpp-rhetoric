#pragma once

#include "./macro.h"

#define RHETORIC_TRY_INIT(type, var, exp) \
type var = exp; \
if (!var) { \
    return rhetoric::Failure(var); \
}

#define RHETORIC_TRY_ASSIGN(var, exp) \
var = exp; \
if (!var) { \
    return rhetoric::Failure(var); \
}

#define RHETORIC_TRY_VOID(exp) \
_RHETORIC_TRY_VOID( RHETORIC_MACRO_CONCAT(rhetoric_void_result_, __COUNTER__) , exp)

#define _RHETORIC_TRY_VOID(var, exp) \
RHETORIC_TRY_INIT(auto, var, exp)

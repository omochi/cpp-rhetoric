#pragma once

#include "./macro.h"

#define RHETORIC_TRY_VOID(expression) _RHETORIC_TRY_VOID_1(__COUNTER__, expression)

#define RHETORIC_TRY_ASSIGN(var, expression) _RHETORIC_TRY_ASSIGN_1(__COUNTER__, var, expression)

// ---

#define _RHETORIC_TRY_RETURN_IF_FAILURE(result_var, expression) \
auto result_var = expression; \
if (!result_var) { \
    return result_var.error(); \
}

#define _RHETORIC_TRY_VOID_1(counter_macro, expression) \
_RHETORIC_TRY_VOID_2(counter_macro, expression)

#define _RHETORIC_TRY_VOID_2(counter, expression) \
_RHETORIC_TRY_RETURN_IF_FAILURE(rhetoric_void_result_ ## counter, expression)

#define _RHETORIC_TRY_ASSIGN_1(counter_macro, var, expression) \
_RHETORIC_TRY_ASSIGN_2(counter_macro, var, expression)

#define _RHETORIC_TRY_ASSIGN_2(counter, var, expression) \
_RHETORIC_TRY_ASSIGN_3(rhetoric_assign_result_ ## counter, var, expression)

#define _RHETORIC_TRY_ASSIGN_3(result_var, var, expression) \
_RHETORIC_TRY_RETURN_IF_FAILURE(result_var, expression) \
var = *result_var;

#pragma once

#include "./platform.h"

#ifdef __cplusplus
#   define RHETORIC_EXTERN_C_BEGIN extern "C" {
#   define RHETORIC_EXTERN_C_END }
#   define RHETORIC_EXTERN_C extern "C"
#else
#   define RHETORIC_EXTERN_C_BEGIN
#   define RHETORIC_EXTERN_C_END
#   define RHETORIC_EXTERN_C
#endif

#define RHETORIC_NO_RETURN [[noreturn]]
#define RHETORIC_UNUSED(x) (void)x

#if RHETORIC_MACOS
#	define RHETORIC_NO_DISCARD [[nodiscard]]
#   define RHETORIC_PRINTF_FORMAT_ARG const char * format
#   define RHETORIC_PRINTF_LIKE(f, a) __attribute__((__format__ (__printf__, f, a)))
#endif

#if RHETORIC_WINDOWS
#	define RHETORIC_NO_DISCARD _Check_return_
#   define RHETORIC_PRINTF_FORMAT_ARG _Printf_format_string_ const char * format
#   define RHETORIC_PRINTF_LIKE(f, a)
#endif

#define RHETORIC_NON_COPYABLE(_type) \
_type(const _type &) = delete;\
_type & operator=(const _type &) = delete



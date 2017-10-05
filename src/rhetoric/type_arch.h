#pragma once

#if defined(__GNUC__)
#   if defined(__LP64__)
#       define RHETORIC_INT_SIZE 8
#       define RHETORIC_LONG_SIZE 8
#       define RHETORIC_LONG_LONG_SIZE 8
#       define RHETORIC_POINTER_SIZE 8
#   else
#       define RHETORIC_INT_SIZE 4
#       define RHETORIC_LONG_SIZE 4
#       define RHETORIC_LONG_LONG_SIZE 8
#       define RHETORIC_POINTER_SIZE 4
#   endif
#elif defined(_MSC_VER)
#   if defined(_WIN64)
#       define RHETORIC_INT_SIZE 4
#       define RHETORIC_LONG_SIZE 4
#       define RHETORIC_LONG_LONG_SIZE 8
#       define RHETORIC_POINTER_SIZE 8
#   else
#       define RHETORIC_INT_SIZE 4
#       define RHETORIC_LONG_SIZE 4
#       define RHETORIC_LONG_LONG_SIZE 8
#       define RHETORIC_POINTER_SIZE 4
#   endif
#endif


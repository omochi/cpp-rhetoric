#pragma once

#define RHETORIC_MACOS 0
#define RHETORIC_WINDOWS 0

#ifdef __APPLE__
#   include <TargetConditionals.h>
#   if TARGET_OS_MAC
#       undef RHETORIC_MACOS
#       define RHETORIC_MACOS 1
#   endif
#endif

#ifdef _WIN32
#   undef RHETORIC_WINDOWS
#   define RHETORIC_WINDOWS 1
#endif

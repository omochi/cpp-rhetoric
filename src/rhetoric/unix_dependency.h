#pragma once

#include "./platform.h"

#include <sys/types.h>
#include <sys/stat.h>

#if RHETORIC_WINDOWS
#	define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#	define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#endif

#if RHETORIC_MACOS
#   include <dirent.h>
#endif

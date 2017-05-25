#pragma once

#include "./platform.h"

#include <sys/types.h>
#include <sys/stat.h>

#ifndef S_ISDIR
#	define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#endif

#ifndef S_ISREG
#	define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#endif

#if RHETORIC_MACOS
#   include <unistd.h>
#   include <dirent.h>
#endif

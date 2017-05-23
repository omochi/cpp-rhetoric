#pragma once

#include "./platform.h"

#if RHETORIC_MACOS
#   include <sys/types.h>
#   include <sys/stat.h>
#   include <unistd.h>
#   include <dirent.h>
#endif

#pragma once

#include "./platform.h"

#if RHETORIC_WINDOWS
#	define NOMINMAX
#	include <Windows.h>
#   include <tchar.h>
#endif

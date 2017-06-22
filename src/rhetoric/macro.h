#pragma once

#include "./platform.h"

#if RHETORIC_MACOS
#   define RHETORIC_PRETTY_FUNCTION __PRETTY_FUNCTION__
#	define RHETORIC_DECLTYPE(...) decltype(__VA_ARGS__)
#endif

#if RHETORIC_WINDOWS
#   define RHETORIC_PRETTY_FUNCTION __FUNCSIG__

//	https://stackoverflow.com/questions/9291336/decltype-and-the-scope-operator-in-c
#	define RHETORIC_DECLTYPE(...) std::identity<decltype(__VA_ARGS__)>::type
#endif

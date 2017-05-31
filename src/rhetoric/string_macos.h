#pragma once

#include "./macos_dependency.h"
#include "./platform.h"
#include "./std_dependency.h"

#if RHETORIC_MACOS

namespace rhetoric {
#ifdef __OBJC__
    NSString * StringToNSString(const std::string & string);
    std::string NSStringToString(NSString * ns_string);
#endif
}

#endif

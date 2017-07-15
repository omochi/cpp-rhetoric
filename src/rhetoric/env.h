#pragma once

#include "./std_dependency.h"
#include "./unix_dependency.h"
#include "./windows_dependency.h"

#include "./defer.h"
#include "./option.h"
#include "./string_windows.h"

namespace rhetoric {
    Option<std::string> GetEnv(const std::string & name);
}

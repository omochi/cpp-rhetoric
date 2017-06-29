#pragma once

#include "./defer.h"
#include "./optional.h"
#include "./std_dependency.h"
#include "./string_windows.h"
#include "./unix_dependency.h"
#include "./windows_dependency.h"

namespace rhetoric {
    Optional<std::string> GetEnv(const std::string & name);
}

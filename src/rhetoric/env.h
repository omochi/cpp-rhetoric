#pragma once

#include "./std_dependency.h"
#include "./unix_dependency.h"
#include "./windows_dependency.h"

#include "./defer.h"
#include "./optional.h"
#include "./string_windows.h"

namespace rhetoric {
    Optional<std::string> GetEnv(const std::string & name);
}

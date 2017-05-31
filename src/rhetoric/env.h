#pragma once

#include "./optional.h"
#include "./std_dependency.h"
#include "./unix_dependency.h"

namespace rhetoric {
    Optional<std::string> GetEnv(const std::string & name);
}

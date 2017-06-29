#pragma once

#include "./platform.h"
#include "./std_dependency.h"

namespace rhetoric {
    errno_t fopen_internal(FILE ** handle_ptr, const char * filename, const char * mode);
}

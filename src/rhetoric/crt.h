#pragma once

#include "./std_dependency.h"
#include "./platform.h"

namespace rhetoric {
    errno_t fopen_internal(FILE ** handle_ptr, const char * filename, const char * mode);
}

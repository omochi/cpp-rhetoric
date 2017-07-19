#pragma once

#include "./std_dependency.h"
#include "./platform.h"

namespace rhetoric {
    errno_t _fopen(FILE ** handle_ptr, const char * filename, const char * mode);
}

#pragma once

#include "./std_dependency.h"

#include "./attribute.h"
#include "./format.h"
#include "./pretty_function_macro.h"

#define RHETORIC_FATAL(message) \
rhetoric::Fatal(message, RHETORIC_PRETTY_FUNCTION, __FILE__, __LINE__)

namespace rhetoric {
    RHETORIC_NO_RETURN
    void Fatal(const std::string & message,
               const char * func,
               const char * file,
               int line);
}

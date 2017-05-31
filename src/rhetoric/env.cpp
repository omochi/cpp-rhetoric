#include "./env.h"

namespace rhetoric {
    Optional<std::string> GetEnv(const std::string & name) {
        const char * cstr = getenv(name.c_str());
        if (!cstr) { return None(); }
        return Some(std::string(cstr));
    }
}

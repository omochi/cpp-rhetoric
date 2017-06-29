#include "./crt.h"

namespace rhetoric {
    errno_t fopen_internal(FILE ** handle_ptr, const char * filename, const char * mode) {
#if RHETORIC_WINDOWS
        return ::fopen_s(handle_ptr, filename, mode);
#else
        FILE * handle = ::fopen(filename, mode);
        if (handle_ptr) {
            *handle_ptr = handle;
        }
        if (!handle) {
            return errno;
        }
        return 0;
#endif
    }
}

#include "./format.h"

namespace rhetoric {
    std::string Format(const char * format, ...) {
        va_list args;
        va_start(args, format);
        auto ret = FormatV(format, args);
        va_end(args);
        return ret;
    }

    std::string FormatV(const char * format, va_list args) {
        va_list args2;
        va_copy(args2, args);

        std::vector<char> buf(1024);

        int len = vsnprintf(buf.data(), buf.size(), format, args);
        if (len < 0) {
            throw std::logic_error("vsnprintf");
        }

        if (len + 1 > buf.size()) {
            buf.resize(len + 1);
            int check_len = vsnprintf(buf.data(), buf.size(), format, args2);
            if (check_len != len) {
                throw std::logic_error("vsnprintf (check)");
            }
        }

        va_end(args2);

        return std::string(buf.data(), len);
    }
}

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

        int print_ret = vsnprintf(buf.data(), buf.size(), format, args);
        if (print_ret < 0) {
            throw std::logic_error("[FormatV] vsnprintf (1) failed");
        }
        size_t len = ToUnsigned(print_ret);
        
        if (len + 1 > buf.size()) {
            buf.resize(len + 1);
            int print2_ret = vsnprintf(buf.data(), buf.size(), format, args2);
            if (print2_ret < 0) {
                throw std::logic_error("[FormatV] vsnprintf (2) failed");
            }
            size_t len2 = ToUnsigned(print2_ret);
            if (len != len2) {
                throw std::logic_error("[FormatV] vsnprintf (2) length check error");
            }
        }

        va_end(args2);

        return std::string(buf.data(), len);
    }
}

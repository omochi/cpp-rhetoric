#include "./int_convertion.h"

namespace rhetoric {
    unsigned char ToUnsigned(char x) {
        RHETORIC_ASSERT(x >= 0);
        return (unsigned char)x;
    }

    unsigned short ToUnsigned(short x) {
        RHETORIC_ASSERT(x >= 0);
        return (unsigned short)x;
    }

    unsigned int ToUnsigned(int x) {
        RHETORIC_ASSERT(x >= 0);
        return (unsigned int)x;
    }
    
    unsigned long ToUnsigned(long x) {
        RHETORIC_ASSERT(x >= 0);
        return (unsigned long)x;
    }
    
    unsigned long long ToUnsigned(long long x) {
        RHETORIC_ASSERT(x >= 0);
        return (unsigned long long)x;
    }
    
    char ToSigned(unsigned char x) {
        auto y = (char)x;
        RHETORIC_ASSERT(y >= 0);
        return y;
    }
    
    short ToSigned(unsigned short x) {
        auto y = (short)x;
        RHETORIC_ASSERT(y >= 0);
        return y;
    }
    
    int ToSigned(unsigned int x) {
        auto y = (int)x;
        RHETORIC_ASSERT(y >= 0);
        return y;
    }
    
    long ToSigned(unsigned long x) {
        auto y = (long)x;
        RHETORIC_ASSERT(y >= 0);
        return y;
    }
    
    long long ToSigned(unsigned long long x) {
        auto y = (long long)x;
        RHETORIC_ASSERT(y >= 0);
        return y;
    }
    
    int ToInt(unsigned int x) {
        return ToSigned(x);
    }
    
    int ToInt(long x) {
        RHETORIC_ASSERT(std::numeric_limits<int>::min() <= x);
        RHETORIC_ASSERT(x <= std::numeric_limits<int>::max());
        return (int)x;
    }
    
    int ToInt(unsigned long x) {
        return ToInt(ToSigned(x));
    }
    
    int ToInt(long long x) {
        RHETORIC_ASSERT(std::numeric_limits<int>::min() <= x);
        RHETORIC_ASSERT(x <= std::numeric_limits<int>::max());
        return (int)x;
    }
    
    int ToInt(unsigned long long x) {
        return ToInt(ToSigned(x));
    }

    size_t ToSize(int x) {
        return ToSize(ToUnsigned(x));
    }

    size_t ToSize(unsigned int x) {
        RHETORIC_ASSERT(std::numeric_limits<size_t>::min() <= x);
        RHETORIC_ASSERT(x <= std::numeric_limits<size_t>::max());
        return (size_t)x;
    }

    size_t ToSize(long x) {
        return ToSize(ToUnsigned(x));
    }

    size_t ToSize(unsigned long x) {
        RHETORIC_ASSERT(std::numeric_limits<size_t>::min() <= x);
        RHETORIC_ASSERT(x <= std::numeric_limits<size_t>::max());
        return (size_t)x;
    }

    size_t ToSize(long long x) {
        return ToSize(ToUnsigned(x));
    }

    size_t ToSize(unsigned long long x) {
        RHETORIC_ASSERT(std::numeric_limits<size_t>::min() <= x);
        RHETORIC_ASSERT(x <= std::numeric_limits<size_t>::max());
        return (size_t)x;
    }
}

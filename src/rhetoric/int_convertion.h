#pragma once

#include "./assert.h"

namespace rhetoric {
    unsigned char ToUnsigned(char x);
    unsigned short ToUnsigned(short x);
    unsigned int ToUnsigned(int x);
    unsigned long ToUnsigned(long x);
    unsigned long long ToUnsigned(long long x);
    
    char ToSigned(unsigned char x);
    short ToSigned(unsigned short x);
    int ToSigned(unsigned int x);
    long ToSigned(unsigned long x);
    long long ToSigned(unsigned long long x);
    
    int ToInt(unsigned int x);
    int ToInt(long x);
    int ToInt(unsigned long x);
    int ToInt(long long x);
    int ToInt(unsigned long long x);
}

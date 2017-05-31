#include "./string_macos.h"

#if RHETORIC_MACOS && defined(__OBJC__)

namespace rhetoric {
    NSString * StringToNSString(const std::string & string) {
        return [NSString stringWithCString:string.c_str()
                                  encoding:NSUTF8StringEncoding];
    }

    std::string NSStringToString(NSString * ns_string) {
        NSData * buf = [ns_string dataUsingEncoding:NSUTF8StringEncoding
                               allowLossyConversion:YES];
        return std::string(((const char *)buf.bytes), (int)buf.length);
    }
}

#endif

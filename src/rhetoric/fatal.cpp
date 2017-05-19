#include "./fatal.h"

namespace rhetoric {
    void Fatal(const std::string & message,
               const char * func,
               const char * file,
               int line)
    {
        auto error_message = Format("%s, func=[%s], file=[%s], line=%d",
                                    message.c_str(),
                                    func,
                                    file,
                                    line);
        throw std::logic_error(error_message);
    }
}

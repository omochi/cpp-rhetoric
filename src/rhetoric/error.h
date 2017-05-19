#pragma once

#include "./ptr.h"

namespace rhetoric {
    class Error : public std::enable_shared_from_this<Error> {
    public:
        virtual ~Error() {}
        virtual std::string ToString() const = 0;
    };
}

#pragma once

#include "./concept_macro.h"
#include "./ptr.h"

namespace rhetoric {
    class Error : public std::enable_shared_from_this<Error> {
    public:
        Error() {}
        virtual ~Error() {}
        
        RHETORIC_NON_COPYABLE(Error)
        
        virtual std::string ToString() const = 0;
    };
}

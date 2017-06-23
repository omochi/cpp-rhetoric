#include "./none.h"

namespace rhetoric {
    bool None::operator==(const None & other) const {
        RHETORIC_UNUSED(other);
        
        return true;
    }
}

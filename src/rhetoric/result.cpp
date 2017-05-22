#include "./result.h"

namespace rhetoric {
    ResultFailure Failure(const Ptr<Error> & error) {
        return ResultFailure { error };
    }
}

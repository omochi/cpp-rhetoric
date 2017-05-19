#include "./assert.h"

namespace rhetoric {
    void Assert(bool condition,
                const char * condition_str,
                const char * func,
                const char * file,
                int line)
    {
        if (!condition) {
            Fatal(Format("Assertion failure: [%s]", condition_str),
                  func, file, line);
        }
    }
}

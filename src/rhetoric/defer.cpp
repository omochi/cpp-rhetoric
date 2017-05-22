#include "./defer.h"

namespace rhetoric {
    Defer::Defer(const std::function<void()> proc):
    proc_(proc)
    {}

    Defer::~Defer(){
        if (proc_) {
            proc_();
        }
    }
}

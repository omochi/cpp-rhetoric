#include "./defer.h"

namespace rhetoric {
    _Defer::_Defer(const std::function<void()> proc):
    proc_(proc)
    {}

    _Defer::~_Defer(){
        if (proc_) {
            proc_();
        }
    }
}

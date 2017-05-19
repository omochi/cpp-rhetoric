#include "./print.h"

namespace rhetoric {
    void Print(const std::string & string, bool new_line) {
        auto & out = std::cout;
        out << string;
        if (new_line) {
            out << "\n";
        }
    }
}

#include "./range.h"

namespace rhetoric {
    Range<size_t> MakeIndexRange(size_t lower_bound, size_t upper_bound) {
        return MakeRange<size_t>(lower_bound, upper_bound);
    }
}

#pragma once

namespace rhetoric {
    struct None {
        bool operator==(const None & other) const;
        bool operator!=(const None & other) const;
    };
}

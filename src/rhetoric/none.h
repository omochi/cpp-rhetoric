#pragma once

#include "./attribute.h"
#include "./concept_macro.h"

namespace rhetoric {
    struct None {
        bool operator==(const None & other) const;
        RHETORIC_EQUATABLE_DEFAULT(None);
    };
}

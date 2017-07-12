#pragma once

#define RHETORIC_SUBCLASS_SHARED_FROM_THIS(this_type, super_type) \
rhetoric::Ptr<const this_type> shared_from_this() const { \
    return std::static_pointer_cast<const this_type>(super_type::shared_from_this()); \
} \
rhetoric::Ptr<this_type> shared_from_this() { \
    return std::static_pointer_cast<this_type>(super_type::shared_from_this()); \
}


#pragma once

namespace rhetoric {
    template <typename T, typename ...Args>
    Ptr<T> New(Args&&... args)
    {
        T * instance = new T(std::forward<Args>(args)...);
        return std::shared_ptr<T>(instance);
    }
}

#pragma once

namespace rhetoric {
    template <typename T, typename ...Args>
    Ptr<T> New(Args&&... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}

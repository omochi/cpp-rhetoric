#pragma once

#include "./std_dependency.h"

namespace rhetoric {
    template <typename T>
    class FunctionTraitImpl;

    template <typename T>
    class FunctionTrait: public FunctionTraitImpl<decltype(&T::operator())>
    {};

    template <typename Receiver, typename Return, typename ...Args>
    class FunctionTraitImpl<Return(Receiver::*)(Args...) const>
    {
    public:
        using ReturnType = Return;
        using ArgsType = std::tuple<Args...>;
    };

}

#pragma once

#include "./std_dependency.h"

#include "./assert.h"
#include "./attribute.h"
#include "./format_macro.h"
#include "./generic_error.h"
#include "./macro.h"
#include "./optional.h"
#include "./result.h"
#include "./int_convertion.h"

namespace rhetoric {
    template <typename A>
    bool
    ArrayCheckIndex(const A & array, size_t index);

    template <typename A>
    RHETORIC_NO_DISCARD
    Result<typename A::value_type>
    ArrayGetAt(const A & array, size_t index);

    template <typename A>
    Optional<typename A::value_type>
    ArrayGetAtOrNone(const A & array, size_t index);
    
    template <typename A, typename P>
    Optional<typename A::value_type>
    ArrayFind(const A & array,
              P && pred);

    template <typename A>
    Optional<typename A::value_type>
    ArrayFindEq(const A & array,
                const typename A::value_type & item);

    template <typename A, typename P>
    Optional<typename A::value_type>
    ArrayFindR(const A & array,
               P && pred);

    template <typename A>
    Optional<typename A::value_type>
    ArrayFindEqR(const A & array,
                 const typename A::value_type & item);

    template <typename A, typename P>
    Optional<size_t>
    ArrayFindIndex(const A & array,
                   P && pred);

    template <typename A>
    Optional<size_t>
    ArrayFindIndexEq(const A & array,
                     const typename A::value_type & item);

    template <typename A, typename P>
    Optional<size_t>
    ArrayFindIndexR(const A & array,
                    P && pred);

    template <typename A>
    Optional<size_t>
    ArrayFindIndexEqR(const A & array,
                      const typename A::value_type & item);

    template <typename A, typename F>
    auto
    ArrayMap(const A & array,
             F && f)
    -> std::vector<  decltype(f(std::declval<  typename A::value_type  >()))  >;

    template <typename A, typename P>
    std::vector<typename A::value_type>
    ArrayFilter(const A & array,
                P && pred);
    
    template <typename A, typename F>
    using ArrayFlatMapResult = std::vector<  typename std::result_of_t< F(typename A::value_type) >::value_type  >;
    
    template <typename A, typename F>
    ArrayFlatMapResult<A, F>
    ArrayFlatMap(const A & array,
                 F && f);
    
    template <typename A, typename F>
    using ArrayFlatMapOptionalResult = std::vector<  typename std::result_of_t< F(typename A::value_type) >::ValueType  >;
    
    template <typename A, typename F>
    ArrayFlatMapOptionalResult<A, F>
    ArrayFlatMapOptional(const A & array,
                         F && f);
    
    template <typename A, typename P>
    void
    ArrayRemove(A * array,
                P && pred);

    template <typename A>
    void
    ArrayRemoveEq(A * array,
                  const typename A::value_type & item);

    template <typename A>
    void
    ArrayRemoveAt(A * array, size_t index);

    template <typename A, typename P>
    bool
    ArrayTestAll(const A & array,
                 P && pred);

    template <typename A, typename P>
    bool
    ArrayTestAny(const A & array,
                 P && pred);

    template <typename A, typename P>
    size_t
    ArrayCount(const A & array,
               P && pred);

    template <typename A>
    void
    ArrayReverse(A * array);

    template <typename A>
    std::vector<typename A::value_type>
    ArrayReversed(const A & array);
}

#include "./array_function_inline.h"

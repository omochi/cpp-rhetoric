namespace rhetoric {
    template <typename A>
    bool
    ArrayCheckIndex(const A & array, size_t index)
    {
        return index < array.size();
    }
    
    template <typename A>
    Result<typename A::value_type>
    ArrayGetAt(const A & array, size_t index)
    {
        if (!ArrayCheckIndex(array, index)) {
            return Failure(GenericError::Create("index is out of range: index=%" PRIdS ", count=%" PRIdS,
                                                index,
                                                (size_t)array.size()));
        }
        return Success(array[index]);
    }

    template <typename A>
    Optional<typename A::value_type>
    ArrayGetAtOrNone(const A & array, size_t index)
    {
        if (!ArrayCheckIndex(array, index)) {
            return None();
        }
        return Some(array[index]);
    }

    template <typename A, typename P>
    Optional<typename A::value_type>
    ArrayFind(const A & array,
              P && pred)
    {
        auto begin = array.cbegin();
        auto end = array.cend();
        auto iter = std::find_if(begin, end, pred);
        if (iter == end) {
            return None();
        }
        return Some(*iter);
    }

    template <typename A>
    Optional<typename A::value_type>
    ArrayFindEq(const A & array,
                const typename A::value_type & item)
    {
        return ArrayFind(array, [=](auto x){ return x == item; });
    }

    template <typename A, typename P>
    Optional<typename A::value_type>
    ArrayFindR(const A & array,
               P && pred)
    {
        auto begin = array.crbegin();
        auto end = array.crend();
        auto iter = std::find_if(begin, end, pred);
        if (iter == end) {
            return None();
        }
        return Some(*iter);
    }

    template <typename A>
    Optional<typename A::value_type>
    ArrayFindEqR(const A & array,
                 const typename A::value_type & item)
    {
        return ArrayFindR(array, [=](auto x){ return x == item; });
    }

    template <typename A, typename P>
    Optional<size_t>
    ArrayFindIndex(const A & array,
                   P && pred)
    {
        auto begin = array.cbegin();
        auto end = array.cend();
        auto iter = std::find_if(begin, end, pred);
        if (iter == end) {
            return None();
        }
        size_t offset = ToUnsigned(iter - begin);
        return Some(offset);
    }

    template <typename A>
    Optional<size_t>
    ArrayFindIndexEq(const A & array,
                     const typename A::value_type & item)
    {
        return ArrayFindIndex(array, [=](auto x) { return x == item; });
    }

    template <typename A, typename P>
    Optional<size_t>
    ArrayFindIndexR(const A & array,
                    P && pred)
    {
        auto begin = array.crbegin();
        auto end = array.crend();
        auto iter = std::find_if(begin, end, pred);
        if (iter == end) {
            return None();
        }
        size_t offset = ToUnsigned(iter - begin);
        return Some(array.size() - 1 - offset);
    }

    template <typename A>
    Optional<size_t>
    ArrayFindIndexEqR(const A & array,
                      const typename A::value_type & item)
    {
        return ArrayFindIndexR(array, [=](auto x) { return x == item; });
    }

    template <typename A, typename F>
    auto
    ArrayMap(const A & array,
             F && f)
    -> std::vector<  decltype(f(std::declval<  typename A::value_type  >()))  >
    {
        std::vector<  decltype(f(std::declval<  typename A::value_type  >()))  > ret;
        for (auto & x : array) {
            auto y = f(x);
            ret.push_back(y);
        }
        return ret;
    }

    template <typename A, typename P>
    std::vector<typename A::value_type>
    ArrayFilter(const A & array,
                P && pred)
    {
        std::vector<typename A::value_type> ret;
        for (auto & x : array) {
            if (pred(x)) {
                ret.push_back(x);
            }
        }
        return ret;
    }
    
    template <typename A, typename F>
    ArrayFlatMapResult<A, F>
    ArrayFlatMap(const A & array,
                 F && f)
    {
		ArrayFlatMapResult<A, F> ret;
        for (auto & x : array) {
            auto items = f(x);
            for (auto & item : items) {
                ret.push_back(item);
            }
        }
        return ret;
    }
    
    template <typename A, typename F>
    ArrayFlatMapOptionalResult<A, F>
    ArrayFlatMapOptional(const A & array,
                         F && f)
    {
        ArrayFlatMapOptionalResult<A, F> ret;
        for (auto & x : array) {
            auto item_opt = f(x);
            if (item_opt) {
                ret.push_back(*item_opt);
            }
        }
        return ret;
    }

    template <typename A, typename P>
    void
    ArrayRemove(A * array,
                P && pred)
    {
        RHETORIC_ASSERT(array != nullptr);
        auto new_end = std::remove_if(array->begin(), array->end(), pred);
        array->erase(new_end, array->end());
    }

    template <typename A>
    void
    ArrayRemoveEq(A * array,
                  const typename A::value_type & item)
    {
        ArrayRemove(array, [item](auto x) { return x == item; });
    }

    template <typename A>
    void
    ArrayRemoveAt(A * array, size_t index)
    {
        RHETORIC_ASSERT(array != nullptr);
        array->erase(array->begin() + ToSigned(index));
    }

    template <typename A, typename P>
    bool
    ArrayTestAll(const A & array,
                 P && pred)
    {
        return std::all_of(array.cbegin(), array.cend(), pred);
    }

    template <typename A, typename P>
    bool
    ArrayTestAny(const A & array,
                 P && pred)
    {
        return std::any_of(array.cbegin(), array.cend(), pred);
    }

    template <typename A, typename P>
    size_t
    ArrayCount(const A & array,
               P && pred)
    {
        size_t c = 0;
        for (auto it = array.cbegin(); it != array.cend(); it++) {
            if (pred(*it)) {
                c += 1;
            }
        }
        return c;
    }

    template <typename A>
    void
    ArrayReverse(A * array) {
        RHETORIC_ASSERT(array != nullptr);
        std::reverse(array->begin(), array->end());
    }

    template <typename A>
    std::vector<typename A::value_type>
    ArrayReversed(const A & array) {
        std::vector<typename A::value_type> ret;
        for (auto it = array.crbegin(); it != array.crend(); it++) {
            ret.push_back(*it);
        }
        return ret;
    }
}

namespace rhetoric {
    template <typename A, typename P>
    Optional<int>
    ArrayFind(const A & array,
              const P & pred)
    {
        auto begin = array.cbegin();
        auto end = array.cend();
        auto iter = std::find_if(begin, end, pred);
        if (iter == end) {
            return None();
        }
        auto offset = (int)(iter - begin);
        return Some(offset);
    }

    template <typename A, typename P>
    Optional<int>
    ArrayFindR(const A & array,
               const P & pred)
    {
        auto begin = array.cbegin();
        auto end = array.cend();
        auto iter = std::find_if(begin, end, pred);
        if (iter == end) {
            return None();
        }
        auto offset = (int)(iter - begin);
        return Some((int)array.size() - 1 - offset);
    }

    template <typename A, typename P>
    void
    ArrayRemove(A & array,
                const P & pred)
    {
        auto new_end = std::remove_if(array.begin(), array.end(), pred);
        array.erase(new_end, array.end());
    }

    template <typename A>
    void
    ArrayRemoveAt(A & array, int index)
    {
        array.erase(array.begin() + index);
    }

    template <typename A, typename P>
    bool
    TestAll(const A & array,
            const P & pred)
    {
        return std::all_of(array.cbegin(), array.cend(), pred);
    }

    template <typename A, typename P>
    bool
    TestAny(const A & array,
            const P & pred)
    {
        return std::any_of(array.cbegin(), array.cend(), pred);
    }
}

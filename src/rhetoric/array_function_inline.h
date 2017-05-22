namespace rhetoric {
    template <typename A, typename C>
    Optional<int>
    ArrayFind(const A & array,
              const T & pred)
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

    template <typename A, typename C>
    Optional<int>
    ArrayFindR(const A & array,
               const T & pred)
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
    ArrayRemove(C & array,
                const P & pred)
    {
        auto new_end = std::remove_if(array.begin(), array.end(), pred);
        std::erase(new_end, array.end());
    }

    template <typename C>
    void
    ArrayRemoveAt(C & array, int index)
    {
        array.erase(array.begin() + index);
    }
}

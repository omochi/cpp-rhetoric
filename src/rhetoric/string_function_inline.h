namespace rhetoric {
    template <typename A>
    std::string Join(const A & array,
                     const std::string & glue)
    {
        return JoinMap(array, glue, [](auto x) { return x; });
    }
    
    template <typename A, typename F>
    std::string JoinMap(const A & array,
                        const std::string & glue,
                        F && to_str)
    {
        std::string ret;
        
        auto iter = array.cbegin();
        if (iter != array.cend()) {
            ret.append(to_str(*iter));
            iter++;
        }
        for (; iter != array.cend(); iter++) {
            ret.append(glue);
            ret.append(to_str(*iter));
        }
        
        return ret;
    }
}

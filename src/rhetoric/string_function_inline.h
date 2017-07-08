namespace rhetoric {
    template <typename A>
    std::string Join(const A & array,
                     const std::string & glue)
    {
        std::string ret;
        
        auto iter = array.cbegin();
        if (iter != array.cend()) {
            ret.append(*iter);
            iter++;
        }
        for (; iter != array.cend(); iter++) {
            ret.append(glue);
            ret.append(*iter);
        }
        
        return ret;
    }
}

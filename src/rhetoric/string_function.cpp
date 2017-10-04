#include "./string_function.h"

namespace rhetoric {
    FindResult::FindResult(size_t index, size_t target_index):
    index(index),
    target_index(target_index)
    {}
    
    bool CheckStartWith(const std::string & string,
                        const std::string & target)
    {
        return CheckStartWith(string, 0, target);
    }
    
    bool CheckEndWith(const std::string & string,
                      const std::string & target)
    {
        return CheckEndWith(string, string.size(), target);
    }
    
    bool CheckStartWith(const std::string & string,
                        size_t check_index,
                        const std::string & target)
    {
        if (!(check_index + target.size() <= string.size())) {
            return false;
        }
        size_t slice_start = check_index;
        std::string sub = string.substr(slice_start, target.size());
        return sub == target;
    }
    
    bool CheckEndWith(const std::string & string,
                      size_t check_index,
                      const std::string & target)
    {
        if (!(target.size() <= check_index && check_index <= string.size())) {
            return false;
        }
        size_t slice_start = check_index - target.size();
        std::string slice = string.substr(slice_start, target.size());
        return slice == target;
    }
    
    Option<FindResult>
    CheckStartWith(const std::string & string,
                   size_t check_index,
                   const std::vector<std::string> & targets)
    {
        for (size_t target_index = 0; target_index < targets.size(); target_index++) {
            auto & target = targets[target_index];
            
            if (CheckStartWith(string, check_index, target)) {
                return Some(FindResult(check_index, target_index));
            }
        }
        return None();
    }
    
    Option<FindResult>
    CheckEndWith(const std::string & string,
                 size_t check_index,
                 const std::vector<std::string> & targets)
    {
        for (size_t target_index = 0; target_index < targets.size(); target_index++) {
            auto & target = targets[target_index];
            
            if (CheckEndWith(string, check_index, target)) {
                return Some(FindResult(check_index - target.size(), target_index));
            }
        }
        return None();
    }

    std::vector<std::string> white_strs()
    {
        return { "\r", "\n", " ", "\t" };
    }

    std::vector<char> white_chars() {
        return { '\r', '\n', ' ', '\t' };
    }
    
    std::vector<std::string> newline_strs() {
        return { "\r\n", "\r", "\n" };
    }
    
    std::vector<char> newline_chars() {
        return { '\n', '\r' };
    }
    
    std::string
    StripL(const std::string & string) {
        return StripL(string, white_strs());
    }

    std::string StripR(const std::string & string) {
        return StripR(string, white_strs());
    }

    std::string Strip(const std::string & string) {
        return Strip(string, white_strs());
    }
    
    std::string StripL(const std::string & string_,
                       const std::vector<std::string> & targets)
    {
        std::string string = string_;
        while (true) {
            auto ret = CheckStartWith(string, 0, targets);
            if (!ret) {
                break;
            }
            size_t target_end = ret->index + targets[ret->target_index].size();
            string = string.substr(target_end, string.size() - target_end);
        }
        return string;
    }
    
    std::string StripR(const std::string & string_,
                       const std::vector<std::string> & targets)
    {
        std::string string = string_;
        while (true) {
            auto ret = CheckEndWith(string, string.size(), targets);
            if (!ret) {
                break;
            }
            string = string.substr(0, ret->index);
        }
        return string;
    }
    
    std::string Strip(const std::string & string,
                      const std::vector<std::string> & targets)
    {
        auto s = string;
        s = StripR(s, targets);
        s = StripL(s, targets);
        return s;
    }
    
    Option<size_t> Find(const std::string & string,
                          const std::string & target)
    {
        return Find(string, 0, target);
    }
    
    Option<size_t> FindR(const std::string & string,
                           const std::string & target)
    {
        return FindR(string, string.size(), target);
    }
    
    Option<size_t> Find(const std::string & string,
                          size_t start_index,
                          const std::string & target)
    {
        auto ret = Find(string, start_index,
                        std::vector<std::string>{ target });
        if (!ret) { return None(); }
        return Some(ret->index);
    }
    
    Option<size_t> FindR(const std::string & string,
                           size_t start_index,
                           const std::string & target)
    {
        auto ret = FindR(string, start_index,
                         std::vector<std::string>{ target });
        if (!ret) { return None(); }
        return Some(ret->index);
    }
    
    Option<FindResult> Find(const std::string & string,
                              size_t start_index,
                              const std::vector<std::string> & targets)
    {
        for (size_t index = start_index; index <= string.size(); index++) {
            auto ret = CheckStartWith(string, index, targets);
            if (ret) {
                return ret;
            }
        }
        return None();
    }
    
    Option<FindResult> FindR(const std::string & string,
                               size_t start_index,
                               const std::vector<std::string> & targets)
    {
        for (size_t i = 0; i < start_index; i++) {
            size_t index = start_index - i;
            auto ret = CheckEndWith(string, index, targets);
            if (ret) {
                return ret;
            }
        }
        return None();
    }

    std::vector<std::string>
    Split(const std::string & string,
          const std::string & separator,
          const Option<size_t> & limit,
          bool keep_separator)
    {
        return Split(string,
                     std::vector<std::string> { separator },
                     limit,
                     keep_separator);
    }
    
    std::vector<std::string>
    SplitR(const std::string & string,
           const std::string & separator,
           const Option<size_t> & limit,
           bool keep_separator)
    {
        return SplitR(string,
                      std::vector<std::string> { separator },
                      limit,
                      keep_separator);
    }
    
    std::vector<std::string>
    Split(const std::string & string,
          const std::vector<std::string> & separators,
          const Option<size_t> & limit,
          bool keep_separator)
    {
        std::vector<std::string> ret;
        SplitIterate(string,
                     separators,
                     limit,
                     keep_separator,
                     [&](auto x) { ret.push_back(x); });
        return ret;
    }
    
    std::vector<std::string>
    SplitR(const std::string & string,
           const std::vector<std::string> & separators,
           const Option<size_t> & limit,
           bool keep_separator)
    {
        std::vector<std::string> ret;
        SplitIterateR(string,
                      separators,
                      limit,
                      keep_separator,
                      [&](auto x) { ret.push_back(x); });
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
    
    void SplitIterate(const std::string & string,
                      const std::vector<std::string> & separators,
                      const Option<size_t> & limit,
                      bool keep_separator,
                      const std::function<void(const std::string &)> & yield)
    {
        if (string.size() == 0) {
            return;
        }
        
        if (limit) {
            if (*limit == 0) {
                return;
            }
        }
        
        size_t element_num = 0;
        size_t element_start = 0;
        size_t element_end = 0;
        
        while (true) {
            if (limit) {
                if (element_num + 1 >= *limit) {
                    break;
                }
            }
            
            auto find_ret = Find(string, element_start, separators);
            if (!find_ret) {
                break;
            }
            auto separator_start = find_ret->index;
            auto & separator = separators[find_ret->target_index];
            auto separator_end = separator_start + separator.size();
            
            if (keep_separator) {
                element_end = separator_start + separator.size();
            } else {
                element_end = separator_start;
            }
            
            auto element = string.substr(element_start, element_end - element_start);
            yield(element);
            element_num += 1;
            
            element_start = separator_end;
        }
        
        element_end = string.size();
        auto element = string.substr(element_start, element_end - element_start);
        yield(element);
        element_num += 1;
    }
    
    void SplitIterateR(const std::string & string,
                       const std::vector<std::string> & separators,
                       const Option<size_t> & limit,
                       bool keep_separator,
                       const std::function<void(const std::string &)> & yield)
    {
        if (string.size() == 0) {
            return;
        }
        
        if (limit) {
            if (*limit == 0) {
                return;
            }
        }
        
        size_t element_num = 0;
        size_t find_start = string.size();
        
        size_t element_start = 0;
        size_t element_end = string.size();
        
        while (true) {
            if (limit) {
                if (element_num + 1 >= *limit) {
                    break;
                }
            }
            
            auto find_ret = FindR(string, find_start, separators);
            if (!find_ret) {
                break;
            }
            auto separator_start = find_ret->index;
            auto & separator = separators[find_ret->target_index];
            auto separator_end = separator_start + separator.size();
            
            element_start = separator_end;
            
            auto element = string.substr(element_start, element_end - element_start);
            yield(element);
            element_num += 1;
            
            find_start = separator_start;
            
            if (keep_separator) {
                element_end = element_start;
            } else {
                element_end = separator_start;
            }
        }
        
        element_start = 0;
        auto element = string.substr(element_start, element_end - element_start);
        yield(element);
        element_num += 1;
    }

    std::vector<std::string> SplitLines(const std::string & string) {
        return Split(string,
                     newline_strs(),
                     None(),
                     true);
    }
    
    void SplitLinesIterate(const std::string & string,
                           const std::function<void(const std::string &)> & yield) {
        return SplitIterate(string,
                            newline_strs(),
                            None(),
                            true,
                            yield);
    }
    
    Ptr<Data> StringToData(const std::string & string) {
        return New<Data>(string.c_str(), string.size());
    }
}




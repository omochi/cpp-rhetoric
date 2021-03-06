#pragma once

#include "./std_dependency.h"

#include "./data.h"
#include "./option.h"
#include "./ptr.h"

namespace rhetoric {
    struct FindResult {
        size_t index;
        size_t target_index;
        
        FindResult(size_t index, size_t target_index);
    };

    bool CheckStartWith(const std::string & string,
                        const std::string & target);
    bool CheckEndWith(const std::string & string,
                      const std::string & target);
    
    bool CheckStartWith(const std::string & string,
                        size_t check_index,
                        const std::string & target);
    bool CheckEndWith(const std::string & string,
                      size_t check_index,
                      const std::string & target);

    Option<FindResult>
    CheckStartWith(const std::string & string,
                   size_t check_index,
                   const std::vector<std::string> & targets);
    
    Option<FindResult>
    CheckEndWith(const std::string & string,
                 size_t check_index,
                 const std::vector<std::string> & targets);
    
    std::vector<std::string> white_strs();
    std::vector<char> white_chars();
    std::vector<std::string> newline_strs();
    std::vector<char> newline_chars();
    
    std::string StripL(const std::string & string);
    std::string StripR(const std::string & string);
    std::string Strip(const std::string & string);

    std::string StripL(const std::string & string,
             const std::vector<std::string> & targets);
    std::string StripR(const std::string & string,
             const std::vector<std::string> & targets);
    std::string Strip(const std::string & string,
            const std::vector<std::string> & targets);
    
    Option<size_t> Find(const std::string & string,
                          const std::string & target);
    
    Option<size_t> FindR(const std::string & string,
                           const std::string & target);

    Option<size_t> Find(const std::string & string,
                          size_t start_index,
                          const std::string & target);
    
    Option<size_t> FindR(const std::string & string,
                           size_t start_index,
                           const std::string & target);
    
    Option<FindResult> Find(const std::string & string,
                              size_t start_index,
                              const std::vector<std::string> & targets);
    
    Option<FindResult> FindR(const std::string & string,
                               size_t start_index,
                               const std::vector<std::string> & targets);

    std::vector<std::string>
    Split(const std::string & string,
          const std::string & separator,
          const Option<size_t> & limit = None(),
          bool keep_separator = false);
    
    std::vector<std::string>
    SplitR(const std::string & string,
           const std::string & separator,
           const Option<size_t> & limit = None(),
           bool keep_separator = false);

    std::vector<std::string>
    Split(const std::string & string,
          const std::vector<std::string> & separators,
          const Option<size_t> & limit = None(),
          bool keep_separator = false);
    
    std::vector<std::string>
    SplitR(const std::string & string,
           const std::vector<std::string> & separators,
           const Option<size_t> & limit = None(),
           bool keep_separator = false);

    void SplitIterate(const std::string & string,
                      const std::vector<std::string> & separators,
                      const Option<size_t> & limit,
                      bool keep_separator,
                      const std::function<void(const std::string &)> & yield);
    
    void SplitIterateR(const std::string & string,
                       const std::vector<std::string> & separators,
                       const Option<size_t> & limit,
                       bool keep_separator,
                       const std::function<void(const std::string &)> & yield);
    
    std::vector<std::string>
    SplitLines(const std::string & string);
    
    void SplitLinesIterate(const std::string & string,
                           const std::function<void(const std::string &)> & yield);

    template <typename A>
    std::string Join(const A & array,
                     const std::string & glue);
    
    Ptr<Data> StringToData(const std::string & string);
}

#include "./string_function_inline.h"




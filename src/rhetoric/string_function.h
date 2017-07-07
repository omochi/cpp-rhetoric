#pragma once

#include "./data.h"
#include "./optional.h"
#include "./std_dependency.h"
#include "./ptr.h"

namespace rhetoric {
    bool CheckStartWith(const std::string & string,
                        const std::string & target);
    bool CheckEndWith(const std::string & string,
                      const std::string & target);

    bool CheckStartWith(const std::string & string,
                        int start_index,
                        const std::string & target);
    bool CheckEndWith(const std::string & string,
                      int start_index,
                      const std::string & target);

    struct FindResult {
        int index;
        int target_index;

		FindResult();
		FindResult(int index, int target_index);
    };

    Optional<FindResult>
    CheckStartWith(const std::string & string,
                   int start_index,
                   const std::vector<std::string> & targets);
    Optional<FindResult>
    CheckEndWith(const std::string & string,
                 int start_index,
                 const std::vector<std::string> & targets);

    std::vector<std::string> white_chars();
    std::vector<std::string> newline_chars();

    std::string StripL(const std::string & string);
    std::string StripR(const std::string & string);
    std::string Strip(const std::string & string);

    std::string
    StripL(const std::string & string,
           const std::vector<std::string> & targets);
    std::string
    StripR(const std::string & string,
           const std::vector<std::string> & targets);
    std::string
    Strip(const std::string & string,
          const std::vector<std::string> & targets);
    
    Optional<int> Find(const std::string & string,
                       const std::string & target);
    Optional<int> FindR(const std::string & string,
                        const std::string & target);

    Optional<int> Find(const std::string & string,
                       int start_index,
                       const std::string & target);
    Optional<int> FindR(const std::string & string,
                        int start_index,
                        const std::string & target);
    
    Optional<FindResult> Find(const std::string & string,
                              int start_index,
                              const std::vector<std::string> & targets);
    Optional<FindResult> FindR(const std::string & string,
                               int start_index,
                               const std::vector<std::string> & targets);

    std::vector<std::string>
    Split(const std::string & string,
          const std::string & separator,
          const Optional<int> limit = None(),
          bool keep_separator = false);
    std::vector<std::string>
    SplitR(const std::string & string,
           const std::string & separator,
           const Optional<int> limit = None(),
           bool keep_separator = false);

    std::vector<std::string>
    Split(const std::string & string,
          const std::vector<std::string> & separators,
          const Optional<int> limit = None(),
          bool keep_separator = false);
    std::vector<std::string>
    SplitR(const std::string & string,
           const std::vector<std::string> & separators,
           const Optional<int> limit = None(),
           bool keep_separator = false);

    void SplitIterate(const std::string & string,
                      const std::vector<std::string> & separators,
                      const Optional<int> limit,
                      bool keep_separator,
                      const std::function<void(const std::string &)> & yield);
    void SplitRIterate(const std::string & string,
                       const std::vector<std::string> & separators,
                       const Optional<int> limit,
                       bool keep_separator,
                       const std::function<void(const std::string &)> & yield);
    
    
    std::vector<std::string>
    SplitLines(const std::string & string);
    
    void SplitLinesIterate(const std::string & string,
                           const std::function<void(const std::string &)> & yield);

    template <typename A>
    std::string Join(const A & array,
                     const std::string & glue);

    template <typename A, typename F>
    std::string JoinMap(const A & array,
                        const std::string & glue,
                        F && to_str);
    
    Ptr<Data> StringToData(const std::string & string);
}

#include "./string_function_inline.h"




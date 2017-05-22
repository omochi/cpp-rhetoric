#pragma once

#include "./optional.h"
#include "./std_dependency.h"

namespace rhetoric {
    bool IsStartWith(const std::string & string,
                     const std::string & prefix);
    bool IsEndWith(const std::string & string,
                   const std::string & suffix);

    std::string Join(const std::vector<std::string> & array,
                     const std::string & glue);

    Optional<int> Find(const std::string & string,
                       const std::string & target);

    Optional<int> Find(const std::string & string,
                       int start_index,
                       const std::string & target);

    struct FindResult {
        int index;
        int target_index;
    };
    
    Optional<FindResult> Find(const std::string & string,
                              int start_index,
                              const std::vector<std::string> & targets);
    
    Optional<int> FindR(const std::string & string,
                        const std::string & target);

    Optional<int> FindR(const std::string & string,
                        int start_index,
                        const std::string & target);

    Optional<FindResult> FindR(const std::string & string,
                               int start_index,
                               const std::vector<std::string> & targets);

    std::vector<std::string>
    Split(const std::string & string,
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
           const std::string & separator,
           const Optional<int> limit = None(),
           bool keep_separator = false);

    std::vector<std::string>
    SplitR(const std::string & string,
           const std::vector<std::string> & separators,
           const Optional<int> limit = None(),
           bool keep_separator = false);

    std::string Join(const std::vector<std::string> & array,
                     const std::string & glue);
}



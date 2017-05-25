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

    std::string Join(const std::vector<std::string> & array,
                     const std::string & glue);

    Ptr<Data> StringToData(const std::string & string);
}



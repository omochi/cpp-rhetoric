#include "./string_function.h"

namespace rhetoric {

    bool CheckStartWith(const std::string & string,
                        const std::string & target)
    {
        return CheckStartWith(string, 0, target);
    }

    bool CheckEndWith(const std::string & string,
                      const std::string & target)
    {
        return CheckEndWith(string, (int)string.size(), target);
    }

    bool CheckStartWith(const std::string & string,
                        int start_index,
                        const std::string & target)
    {
        auto ret = CheckStartWith(string, start_index, std::vector<std::string> { target });
        if (!ret) { return false; }
        return true;
    }

    bool CheckEndWith(const std::string & string,
                      int start_index,
                      const std::string & target)
    {
        auto ret = CheckEndWith(string, start_index, std::vector<std::string> { target });
        if (!ret) { return false; }
        return true;
    }

    Optional<FindResult>
    CheckStartWith(const std::string & string,
                   int start_index,
                   const std::vector<std::string> & targets)
    {
        for (int target_index = 0;
             target_index < (int)targets.size();
             target_index++)
        {
            auto & target = targets[target_index];
            int sub_index = start_index;
            if (sub_index + target.size() > string.size()) {
                continue;
            }
            auto sub = string.substr(sub_index, target.size());
            if (sub == target) {
                return Some(FindResult {
                    .index = sub_index,
                    .target_index = target_index
                });
            }
        }
        return None();
    }

    Optional<FindResult>
    CheckEndWith(const std::string & string,
                 int start_index,
                 const std::vector<std::string> & targets)
    {
        for (int target_index = 0;
             target_index < (int)targets.size();
             target_index++)
        {
            auto & target = targets[target_index];
            int sub_index = start_index - (int)target.size();
            if (sub_index < 0) {
                continue;
            }
            auto sub = string.substr(sub_index, target.size());
            if (sub == target) {
                return Some(FindResult {
                    .index = sub_index,
                    .target_index = target_index
                });
            }
        }
        return None();
    }

    std::vector<std::string> white_chars()
    {
        return { "\r", "\n", " ", "\t" };
    }

    std::string
    StripL(const std::string & string) {
        return StripL(string, white_chars());
    }

    std::string StripR(const std::string & string) {
        return StripR(string, white_chars());
    }

    std::string Strip(const std::string & string) {
        return Strip(string, white_chars());
    }

    std::string
    StripL(const std::string & string_,
           const std::vector<std::string> & targets)
    {
        std::string string = string_;
        while (true) {
            auto ret = CheckStartWith(string, 0, targets);
            if (!ret) {
                return string;
            }
            string = string.substr(ret->index, (int)string.size() - ret->index);
        }
    }

    std::string
    StripR(const std::string & string_,
           const std::vector<std::string> & targets)
    {
        std::string string = string_;
        while (true) {
            auto ret =  CheckEndWith(string, (int)string.size(), targets);
            if (!ret) {
                return string;
            }
            string = string.substr(0, ret->index);
        }
    }

    std::string
    Strip(const std::string & string_,
          const std::vector<std::string> & targets)
    {
        std::string string = string_;
        string = StripR(string, targets);
        string = StripL(string, targets);
        return string;
    }

    Optional<int> Find(const std::string & string,
                       const std::string & target)
    {
        return Find(string, 0, target);
    }

    Optional<int> FindR(const std::string & string,
                        const std::string & target)
    {
        return FindR(string, (int)string.size(), target);
    }

    Optional<int> Find(const std::string & string,
                       int start_index,
                       const std::string & target)
    {
        auto ret = Find(string, start_index, std::vector<std::string>{ target });
        if (!ret) { return None(); }
        return Some(ret->index);
    }

    Optional<int> FindR(const std::string & string,
                        int start_index,
                        const std::string & target)
    {
        auto ret = FindR(string, (int)string.size(), std::vector<std::string>{ target });
        if (!ret) { return None(); }
        return Some(ret->index);
    }

    Optional<FindResult> Find(const std::string & string,
                              int start_index,
                              const std::vector<std::string> & targets)
    {
        for (int index = start_index; index <= string.size(); index++) {
            auto start_result = CheckStartWith(string, index, targets);
            if (start_result) {
                return start_result;
            }
        }
        return None();
    }

    Optional<FindResult> FindR(const std::string & string,
                               int start_index,
                               const std::vector<std::string> & targets)
    {
        for (int right_index = start_index; right_index >= 0; right_index--) {
            auto end_result = CheckEndWith(string, right_index, targets);
            if (end_result) {
                return end_result;
            }
        }
        return None();
    }

    std::vector<std::string>
    Split(const std::string & string,
          const std::string & separator,
          const Optional<int> limit,
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
           const Optional<int> limit,
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
          const Optional<int> limit,
          bool keep_separator)
    {
        if (limit) {
            RHETORIC_ASSERT(*limit >= 0);
        }

        if (string.size() == 0) {
            return {};
        }

        if (limit) {
            if (*limit == 0) {
                return {};
            }
        }

        std::vector<std::string> elements;
        int pos = 0;

        while (true) {
            if (limit) {
                if (elements.size() >= *limit) {
                    break;
                }
            }

            auto find_ret = Find(string,
                                 pos,
                                 separators);
            if (!find_ret) {
                break;
            }
            auto found_pos = find_ret->index;
            auto & found_separator = separators[find_ret->target_index];

            int next_pos = found_pos + (int)found_separator.size();

            int element_end_index;
            if (keep_separator) {
                element_end_index = next_pos;
            } else {
                element_end_index = found_pos;
            }

            auto element = string.substr(pos, element_end_index - pos);
            elements.push_back(element);

            pos = next_pos;
        }

        auto last_element = string.substr(pos, string.size() - pos);
        elements.push_back(last_element);

        return elements;
    }

    std::vector<std::string>
    SplitR(const std::string & string,
           const std::vector<std::string> & separators,
           const Optional<int> limit,
           bool keep_separator)
    {
        if (limit) {
            RHETORIC_ASSERT(*limit >= 0);
        }

        if (string.size() == 0) {
            return {};
        }

        if (limit) {
            if (*limit == 0) {
                return {};
            }
        }

        std::vector<std::string> elements;
        int pos = (int)string.size();

        while (true) {
            if (limit) {
                if (elements.size() >= *limit) {
                    break;
                }
            }

            auto find_ret = FindR(string,
                                  pos,
                                  separators);
            if (!find_ret) {
                break;
            }
            auto found_pos = find_ret->index;
            auto & found_separator = separators[find_ret->target_index];

            int next_pos = found_pos;

            int element_start_index;
            if (keep_separator) {
                element_start_index = next_pos;
            } else {
                element_start_index = found_pos + (int)found_separator.size();
            }

            auto element = string.substr(element_start_index,
                                         pos - element_start_index);
            elements.push_back(element);

            pos = next_pos;
        }

        auto last_element = string.substr(0, pos);
        elements.push_back(last_element);
        
        return elements;
    }

    std::string Join(const std::vector<std::string> & array,
                     const std::string & glue)
    {
        std::string ret;
        if (array.size() >= 1) {
            ret.append(array[0]);
        }
        for (int i = 1; i < array.size(); i++) {
            ret.append(glue);
            ret.append(array[i]);
        }
        return ret;
    }
}




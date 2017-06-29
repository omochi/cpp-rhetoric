#include "./env.h"

namespace rhetoric {
    Optional<std::string> GetEnv(const std::string & name) {
#if RHETORIC_WINDOWS
        WinString name_win = StringToWinString(name, CP_UTF8);
        TCHAR * str = nullptr;
        size_t len;
        RHETORIC_DEFER([&str] {
            free(str);
        });
        auto err = _tdupenv_s(&str, &len, name_win.c_str());
        if (err) { return None(); }
        if (!str) { return None(); }
        return Some(WinStringToString(WinString(str), CP_UTF8));
#else
        const char * cstr = getenv(name.c_str());
        if (!cstr) { return None(); }
        return Some(std::string(cstr));
#endif
    }
}

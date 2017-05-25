#include "./win32_error.h"

#if RHETORIC_WINDOWS

namespace rhetoric {
	Win32Error::Win32Error(DWORD code, const std::string & message) :
		code_(code),
		message_(message)
	{}

	std::string Win32Error::ToString() const {
		return Format("PosixError(%s(%d), %s)",
			GetWin32ErrorString(code_).c_str(),
			code_,
			message_.c_str());
	}

	DWORD Win32Error::code() const {
		return code_;
	}

	std::string Win32Error::message() const {
		return message_;
	}

	Ptr<Win32Error> Win32Error::Create(DWORD code, const char * format, ...) {
		va_list args;
		va_start(args, format);
		auto ret = New<Win32Error>(code, FormatV(format, args));
		va_end(args);
		return ret;
	}

	std::string GetWin32ErrorString(DWORD code) {
		DWORD flags = FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM;
		LPTSTR message;
		DWORD format_ret = FormatMessage(
			flags,
			nullptr,
			code,
			0,
			(LPWSTR)&message,
			0,
			nullptr);
		RHETORIC_ASSERT(format_ret != 0);
		RHETORIC_DEFER([=] {
			HLOCAL ret = LocalFree(message);
			RHETORIC_ASSERT(ret == 0);
		});
		return WinStringToString(WinString(message), CP_UTF8);
	}
}

#endif

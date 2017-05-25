#include "./string_windows.h"

#if RHETORIC_WINDOWS

namespace rhetoric {
	
	std::wstring StringToWideString(const std::string & string, UINT code_page) {
		DWORD flags = 0;
		int size = MultiByteToWideChar(
			code_page,
			flags,
			string.c_str(),
			-1,
			nullptr,
			0);
		RHETORIC_ASSERT(size != 0);
		std::vector<wchar_t> buf(size);
		int size2 = MultiByteToWideChar(
			code_page,
			flags,
			string.c_str(),
			-1,
			buf.data(),
			(int)buf.size());
		RHETORIC_ASSERT(size2 != 0);
		RHETORIC_ASSERT(size == size2);
		return std::wstring(buf.data());
	}

	std::string WideStringToString(const std::wstring & wstring, UINT code_page) {
		DWORD flags = 0;
		int size = WideCharToMultiByte(
			code_page,
			flags,
			wstring.c_str(),
			-1,
			nullptr,
			0,
			nullptr,
			nullptr);
		RHETORIC_ASSERT(size != 0);
		std::vector<char> buf(size);
		int size2 = WideCharToMultiByte(
			code_page,
			flags,
			wstring.c_str(),
			-1,
			buf.data(),
			(int)buf.size(),
			nullptr,
			nullptr);
		RHETORIC_ASSERT(size2 != 0);
		RHETORIC_ASSERT(size == size2);
		return std::string(buf.data());
	}

	WinString StringToWinString(const std::string & string, UINT code_page) {
#ifdef UNICODE
		return StringToWideString(string, code_page);
#else
		auto wstring = StringToWideString(string, code_page);
		return WideStringToString(wstring, GetACP());
#endif
	}

	std::string WinStringToString(const WinString & winstring, UINT code_page) {
#ifdef UNICODE
		return WideStringToString(winstring, code_page);
#else
		auto wstring = StringToWideString(winstring, GetACP());
		return WideStringToString(wstring, code_page);
#endif
	}

}

#endif
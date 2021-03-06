#pragma once

#include "./std_dependency.h"
#include "./windows_dependency.h"

#include "./assert.h"
#include "./platform.h"

#if RHETORIC_WINDOWS

namespace rhetoric {
#ifdef UNICODE
	using WinString = std::wstring;
#else
	//	current code page
	using WinString = std::string;
#endif

	std::wstring StringToWideString(const std::string & string, UINT code_page);
	std::string WideStringToString(const std::wstring & wstring, UINT code_page);
	
	WinString StringToWinString(const std::string & string, UINT code_page);
	std::string WinStringToString(const WinString & winstring, UINT code_page);
}

#endif

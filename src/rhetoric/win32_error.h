#pragma once

#include "./assert.h"
#include "./attribute.h"
#include "./defer.h"
#include "./error.h"
#include "./format.h"
#include "./string_windows.h"
#include "./windows_dependency.h"

namespace rhetoric {
	class Win32Error : public Error {
	public:
		Win32Error(DWORD code, const std::string & message);
		virtual std::string ToString() const override;

		DWORD code() const;
		std::string message() const;

		static Ptr<Win32Error>
			Create(DWORD code, RHETORIC_PRINTF_FORMAT_ARG, ...) RHETORIC_PRINTF_LIKE(2, 3);
	private:
		DWORD code_;
		std::string message_;
	};

	std::string GetWin32ErrorString(DWORD code);
}
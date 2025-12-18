#include "utility/error_log.h"
#include <comdef.h>

namespace wwist::utils {
	void ErrorLog::output(const std::string &msg) {
		auto error_msg = "*ERROR: " + msg;
		MessageBoxA(NULL, error_msg.c_str(), "Error", MB_ICONERROR);
	}

	void ErrorLog::output(HRESULT hr, const std::string &msg) {
		_com_error error(hr);
		std::wstring error_msg;

		error_msg += L"*ERROR: " + StringConverter::to_wstring(msg) + L"\n";
		// TODO: ProjectSettingの文字コードをUnicodeにした後に実装する.
		// error_msg += error.ErrorMessage();

		MessageBoxW(NULL, error_msg.c_str(), L"Error", MB_ICONERROR);
	}
}

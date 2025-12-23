#include "utils/string_converter.h"

namespace wwist::utils {
	std::wstring StringConverter::to_wstring(const std::string &str) {
		std::wstring w_str(str.begin(), str.end());
		return w_str;
	}
}

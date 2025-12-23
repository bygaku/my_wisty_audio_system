#ifndef STRING_CONVERTER_HEADER
#define STRING_CONVERTER_HEADER

#include <string>

namespace wwist::utils {
	class StringConverter {
	public:
		/**
		 * @brief Convert String to WString.
		 * @return wstring data.
		 */
		static std::wstring to_wstring(const std::string& str);
	};
}

#endif // STRING_CONVERTER_HEADER
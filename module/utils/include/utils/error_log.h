#ifndef ERROR_LOG_HEADER
#define ERROR_LOG_HEADER

#include "string_converter.h"
#include <window.h>

namespace wwist::utils {

class ErrorLog {
public:
	/**
	 * @brief Output error log.
	 * @param msg string data.
	 */
	static void output(const std::string& msg);

	/**
	 * @brief Output error log.
	 * @param hr error code.
	 * @param msg string data.
	 */
	static void output(HRESULT hr, const std::string& msg);
};

}


#endif // ERROR_LOG_HEADER

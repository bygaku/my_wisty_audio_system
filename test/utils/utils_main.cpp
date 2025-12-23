#include <gtest/gtest.h>

#include "utils/string_converter.h"
#include "utils/error_log.h"
using namespace wwist::utils;

// Test StringConverter class - passed.
TEST(StringConverter, ToWString) {
	const auto expected = StringConverter::to_wstring("string");
	const std::wstring actual = L"string";

	ASSERT_STREQ(expected.c_str(), actual.c_str());
}

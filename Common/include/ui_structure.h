#ifndef UI_STRUCTURE_HEADER
#define UI_STRUCTURE_HEADER
#include <string>

namespace wwist::ui {
	/**
	 * @brief Information displayed on BankTree
	 */
	struct SampleEntry {
		int			index_;
		std::string tag_;
		std::string path_;
	};

}


#endif // UI_STRUCTURE_HEADER
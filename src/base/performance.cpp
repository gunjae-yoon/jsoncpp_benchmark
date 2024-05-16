#include <base/performance.h>

namespace jcbm {
	std::filesystem::path Performance::FLAT_TEXT_FILE_PATH = "";
	std::filesystem::path Performance::NESTED_TEXT_FILE_PATH = "";
	const uint64_t Performance::REPEAT_COUNT = 10;

	Performance::Performance() {
	}

	Performance::~Performance() {
	}
}

#ifndef __jsoncpp_benchmark_base_performance_h__
#define __jsoncpp_benchmark_base_performance_h__

#include <chrono>
#include <filesystem>

namespace jcbm {
	class Performance {
	public:
		static std::filesystem::path FLAT_TEXT_FILE_PATH;
		static std::filesystem::path NESTED_TEXT_FILE_PATH;

	public:
		Performance();
		virtual ~Performance();
		
		virtual std::chrono::nanoseconds parseFlatText() const = 0;
		virtual std::chrono::nanoseconds parseNestedText() const = 0;
	};
}

#endif

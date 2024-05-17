#ifndef __jsoncpp_benchmark_impl_nlohmann_h__
#define __jsoncpp_benchmark_impl_nlohmann_h__

#include <base/functional.h>
#include <base/performance.h>

namespace jcbm {
	class Nlohmann : public Functional, Performance {
	public:
		Nlohmann();
		virtual ~Nlohmann();

		// Functinoal test
		bool doesDomKeepOrder(const std::string& q = Functional::question.text, const std::list<std::string>& a = Functional::answer.list) const override;
		bool doesSaxKeepOrder(const std::list<std::string>& q = Functional::question.list, const std::list<std::string>& a = Functional::answer.list) const override;
		
		// Performance test
		std::chrono::nanoseconds parseFlatText() const override;
		std::chrono::nanoseconds parseNestedText() const override;
	};
}

#endif

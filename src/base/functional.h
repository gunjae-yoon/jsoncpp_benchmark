#ifndef __jsoncpp_benchmark_base_functional_h__
#define __jsoncpp_benchmark_base_functional_h__

#include <chrono>
#include <string>
#include <list>

namespace jcbm {
	class Functional {
	private:
		struct QA {
			std::string text;
			std::list<std::string> list;
		};
	public:
		static const QA question;
		static const QA answer;

	public:
		Functional();
		virtual ~Functional();
		
		virtual bool doesDomKeepOrder(const std::string& q, const std::list<std::string>& a) const = 0;
		virtual bool doesSaxKeepOrder(const std::list<std::string>& q, const std::list<std::string>& a) const = 0;
	};
}

#endif

#ifndef __jsoncpp_benchmark_impl_rapidjson_h__
#define __jsoncpp_benchmark_impl_rapidjson_h__

#include <base/functional.h>

namespace jcbm {
	class RapidJson : public Functional {
	public:
		RapidJson();
		virtual ~RapidJson();

		bool doesDomKeepOrder(const std::string& q, const std::list<std::string>& a) const override;
		bool doesSaxKeepOrder(const std::list<std::string>& q, const std::list<std::string>& a) const override;
	};
}

#endif

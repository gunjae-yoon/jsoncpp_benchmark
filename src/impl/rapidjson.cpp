#include <impl/rapidjson.h>

namespace jcbm {
	RapidJson::RapidJson() {
	}

	RapidJson::~RapidJson() {
	}

	bool RapidJson::doesDomKeepOrder(const std::string& q, const std::list<std::string>& a) const {
		return true;
	}

	bool RapidJson::doesSaxKeepOrder(const std::list<std::string>& q, const std::list<std::string>& a) const {
		return true;
	}
}

#include <impl/nlohmann.h>

using namespace std::chrono_literals;

namespace jcbm {
	Nlohmann::Nlohmann() {
	}

	Nlohmann::~Nlohmann() {
	}

	bool Nlohmann::doesDomKeepOrder(const std::string& q, const std::list<std::string>& a) const {
		return true;
	}

	bool Nlohmann::doesSaxKeepOrder(const std::list<std::string>& q, const std::list<std::string>& a) const {
		return true;
	}

	std::chrono::nanoseconds Nlohmann::parseFlatText() const {
		return 0ns;
	}

	std::chrono::nanoseconds Nlohmann::parseNestedText() const {
		return 0ns;
	}
}

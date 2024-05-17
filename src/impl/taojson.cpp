#include <impl/taojson.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std::chrono_literals;

namespace jcbm {
	TaoJson::TaoJson() {
	}

	TaoJson::~TaoJson() {
	}

	bool TaoJson::doesDomKeepOrder(const std::string& q, const std::list<std::string>& a) const {
		return true;
	}

	bool TaoJson::doesSaxKeepOrder(const std::list<std::string>& q, const std::list<std::string>& a) const {
		return true;
	}

	std::chrono::nanoseconds TaoJson::parseFlatText() const {
		return 0ns;
	}

	std::chrono::nanoseconds TaoJson::parseNestedText() const {
		return 0ns;
	}
}

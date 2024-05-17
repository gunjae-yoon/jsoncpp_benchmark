#include <impl/nlohmann.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <list>

using json = nlohmann::json;
using namespace std::chrono_literals;

namespace jcbm {
	Nlohmann::Nlohmann() {
	}

	Nlohmann::~Nlohmann() {
	}

	bool Nlohmann::doesDomKeepOrder(const std::string& q, const std::list<std::string>& a) const {
		// step 1. parse a JSON string into DOM
		json document = json::parse(q);

		// step 2. access sequentially
		json::iterator qIter = document.begin();
		std::list<std::string>::const_iterator aIter = a.begin();
		while (qIter != document.end()) {
			std::cout << "parsing result: " << qIter.key() << ", expected result: " << (*aIter) << std::endl;
			
			// step 2.1. check result
			if (qIter.key() != (*aIter)) {
				return false;
			}

			// step 2.2. do next
			qIter++;
			aIter++;
		}
		return true;
	}

	bool Nlohmann::doesSaxKeepOrder(const std::list<std::string>& q, const std::list<std::string>& a) const {
		// step 1. create an empty JSON object
		// step 2. add members
		// step 3. access sequentially
		return true;
	}

	std::chrono::nanoseconds Nlohmann::parseFlatText() const {
		// step 1. read stream from file
		// step 2. parse a JSON string into DOM
		return 0ns;
	}

	std::chrono::nanoseconds Nlohmann::parseNestedText() const {
		// step 1. read stream from file
		// step 2. parse a JSON string into DOM
		return 0ns;
	}
}

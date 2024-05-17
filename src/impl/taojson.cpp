#include <impl/taojson.h>
#include <tao/json.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace tao;
using namespace std::chrono_literals;

namespace jcbm {
	TaoJson::TaoJson() {
	}

	TaoJson::~TaoJson() {
	}

	bool TaoJson::doesDomKeepOrder(const std::string& q, const std::list<std::string>& a) const {
		// step 1. parse a JSON string into DOM
		json::value document = tao::json::from_string(q);

		// step 2. access sequentially
		if (document.is_object()) {
			json::value::object_t::const_iterator qIter = document.get_object().begin();
			std::list<std::string>::const_iterator aIter = a.begin();
			while (qIter != document.get_object().end()) {
				std::cout << "parsing result: " << qIter->first << ", expected result: " << (*aIter) << std::endl;
				
				// step 2.1. check result
				if (qIter->first != (*aIter)) {
					return false;
				}
		
				// step 2.2. do next
				qIter++;
				aIter++;
			}
		} else {
			return false;
		}

		return true;
	}

	bool TaoJson::doesSaxKeepOrder(const std::list<std::string>& q, const std::list<std::string>& a) const {
		// step 1. create an empty JSON object
		json::value document = json::empty_object;
		
		// step 2. add members
		for (const std::string& elem: q) {
			document[elem] = "";
		}

		// step 3. access sequentially
		if (document.is_object()) {
			json::value::object_t::const_iterator qIter = document.get_object().begin();
			std::list<std::string>::const_iterator aIter = a.begin();
			while (qIter != document.get_object().end()) {
				std::cout << "parsing result: " << qIter->first << ", expected result: " << (*aIter) << std::endl;
				
				// step 3.1. check result
				if (qIter->first != (*aIter)) {
					return false;
				}
		
				// step 3.2. do next
				qIter++;
				aIter++;
			}
		} else {
			return false;
		}

		return true;
	}

	std::chrono::nanoseconds TaoJson::parseFlatText() const {
		return 0ns;
	}

	std::chrono::nanoseconds TaoJson::parseNestedText() const {
		return 0ns;
	}
}

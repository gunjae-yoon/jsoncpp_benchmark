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
		// step 1. read stream from file
		std::ifstream file(Performance::FLAT_TEXT_FILE_PATH);
		if (file.is_open() == false) {
			return 0ns;
		}

		std::stringstream stream;
		stream << file.rdbuf();
		std::string text = stream.str();

		// step 2. parse a JSON string into DOM
		json::value document = json::empty_object;
		std::vector<std::chrono::nanoseconds> results;
		
		for (size_t cnt = 0; cnt < Performance::REPEAT_COUNT; cnt++) {
			std::chrono::time_point begin = std::chrono::system_clock::now();
			document = json::from_string(text.c_str());
			std::chrono::time_point end = std::chrono::system_clock::now();
			results.push_back(end - begin);
			document = json::empty_object;
			//printf("[%2lu] result: %9lu\n", cnt, results[cnt].count());
		}
		
		uint64_t total = 0;
		for (std::chrono::nanoseconds& result : results) {
			total += result.count();
		}
		//printf("average: %9lu\n", (total / Performance::REPEAT_COUNT));

		return std::chrono::nanoseconds(total / Performance::REPEAT_COUNT);
	}

	std::chrono::nanoseconds TaoJson::parseNestedText() const {
		// step 1. read stream from file
		std::ifstream file(Performance::NESTED_TEXT_FILE_PATH);
		if (file.is_open() == false) {
			return 0ns;
		}

		std::stringstream stream;
		stream << file.rdbuf();
		std::string text = stream.str();

		// step 2. parse a JSON string into DOM
		json::value document = json::empty_object;
		std::vector<std::chrono::nanoseconds> results;
		
		for (size_t cnt = 0; cnt < Performance::REPEAT_COUNT; cnt++) {
			std::chrono::time_point begin = std::chrono::system_clock::now();
			document = json::from_string(text.c_str());
			std::chrono::time_point end = std::chrono::system_clock::now();
			results.push_back(end - begin);
			document = json::empty_object;
			//printf("[%2lu] result: %9lu\n", cnt, results[cnt].count());
		}
		
		uint64_t total = 0;
		for (std::chrono::nanoseconds& result : results) {
			total += result.count();
		}
		//printf("average: %9lu\n", (total / Performance::REPEAT_COUNT));

		return std::chrono::nanoseconds(total / Performance::REPEAT_COUNT);
	}
}

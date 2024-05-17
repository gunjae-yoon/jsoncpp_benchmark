#include <impl/nlohmann.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>

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
		if (document.is_object()) {
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
		} else {
			return false;
		}

		return true;
	}

	bool Nlohmann::doesSaxKeepOrder(const std::list<std::string>& q, const std::list<std::string>& a) const {
		// step 1. create an empty JSON object
		json document;
		document = {};
		
		// step 2. add members
		for (const std::string& elem: q) {
			document[elem] = "";
		}

		// step 3. access sequentially
		if (document.is_object()) {
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
		} else {
			return false;
		}

		return true;
	}

	std::chrono::nanoseconds Nlohmann::parseFlatText() const {
		// step 1. read stream from file
		std::ifstream file(Performance::FLAT_TEXT_FILE_PATH);
		if (file.is_open() == false) {
			return 0ns;
		}

		std::stringstream stream;
		stream << file.rdbuf();
		std::string text = stream.str();

		// step 2. parse a JSON string into DOM
		json document;
		std::vector<std::chrono::nanoseconds> results;
		
		for (size_t cnt = 0; cnt < Performance::REPEAT_COUNT; cnt++) {
			std::chrono::time_point begin = std::chrono::system_clock::now();
			document = json::parse(text.c_str());
			std::chrono::time_point end = std::chrono::system_clock::now();
			results.push_back(end - begin);
			document = {};
			//printf("[%2lu] result: %9lu\n", cnt, results[cnt].count());
		}
		
		uint64_t total = 0;
		for (std::chrono::nanoseconds& result : results) {
			total += result.count();
		}
		//printf("average: %9lu\n", (total / Performance::REPEAT_COUNT));

		return std::chrono::nanoseconds(total / Performance::REPEAT_COUNT);
	}

	std::chrono::nanoseconds Nlohmann::parseNestedText() const {
		// step 1. read stream from file
		std::ifstream file(Performance::NESTED_TEXT_FILE_PATH);
		if (file.is_open() == false) {
			return 0ns;
		}

		std::stringstream stream;
		stream << file.rdbuf();
		std::string text = stream.str();

		// step 2. parse a JSON string into DOM
		json document;
		std::vector<std::chrono::nanoseconds> results;
		
		for (size_t cnt = 0; cnt < Performance::REPEAT_COUNT; cnt++) {
			std::chrono::time_point begin = std::chrono::system_clock::now();
			document = json::parse(text.c_str());
			std::chrono::time_point end = std::chrono::system_clock::now();
			results.push_back(end - begin);
			document = {};
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

#include <impl/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>
#include <fstream>
#include <sstream>

using rapidjson::Document;
using rapidjson::Value;
using namespace std::chrono_literals;

namespace jcbm {
	RapidJson::RapidJson() {
	}

	RapidJson::~RapidJson() {
	}

	bool RapidJson::doesDomKeepOrder(const std::string& q, const std::list<std::string>& a) const {
		// step 1. parse a JSON string into DOM
		Document document;
		document.Parse(q.c_str());
		
		// step 2. access sequentially
		if (document.IsObject()) {
			Value::ConstMemberIterator qIter = document.MemberBegin();
			std::list<std::string>::const_iterator aIter = a.begin();
			while (qIter != document.MemberEnd()) {
				std::cout << "parsing result: " << qIter->name.GetString() << ", expected result: " << (*aIter) << std::endl;

				// step 2.1. check result
				if (qIter->name.GetString() != (*aIter)) {
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

	bool RapidJson::doesSaxKeepOrder(const std::list<std::string>& q, const std::list<std::string>& a) const {
		// step 1. create an empty JSON object
		Document document;
		document.SetObject();
		Document::AllocatorType& allocator = document.GetAllocator();
		
		// step 2. add members
		for (const std::string& elem: q) {
			Value key;
			key.SetString(elem.c_str(), allocator);
			document.AddMember(key, "", allocator);
		}

		// step 3. access sequentially
		if (document.IsObject()) {
			Value::ConstMemberIterator qIter = document.MemberBegin();
			std::list<std::string>::const_iterator aIter = a.begin();
			while (qIter != document.MemberEnd()) {
				std::cout << "parsing result: " << qIter->name.GetString() << ", expected result: " << (*aIter) << std::endl;

				// step 3.1. check result
				if (qIter->name.GetString() != (*aIter)) {
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

	std::chrono::nanoseconds RapidJson::parseFlatText() const {
		// step 1. read stream from file
		std::ifstream file(Performance::FLAT_TEXT_FILE_PATH);
		if (file.is_open() == false) {
			return 0ns;
		}

		std::stringstream stream;
		stream << file.rdbuf();
		std::string text = stream.str();

		// step 2. parse a JSON string into DOM
		Document document;
		
		std::chrono::time_point begin = std::chrono::system_clock::now();
		document.Parse(text.c_str());
		std::chrono::time_point end = std::chrono::system_clock::now();

		return (end - begin);
	}

	std::chrono::nanoseconds RapidJson::parseNestedText() const {
		// step 1. read stream from file
		std::ifstream file(Performance::NESTED_TEXT_FILE_PATH);
		if (file.is_open() == false) {
			return 0ns;
		}

		std::stringstream stream;
		stream << file.rdbuf();
		std::string text = stream.str();

		// step 2. parse a JSON string into DOM
		Document document;
		
		std::chrono::time_point begin = std::chrono::system_clock::now();
		document.Parse(text.c_str());
		std::chrono::time_point end = std::chrono::system_clock::now();

		return (end - begin);
	}
}

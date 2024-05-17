#include <version.h>
#include <iostream>

#include <impl/rapidjson.h>
#include <impl/nlohmann.h>

using namespace jcbm;

int main(int argc, char** argv) {
	std::cout << "version: " << Version::full << std::endl;
	
	std::cout << std::endl;
	std::cout << "---------- RapidJSON ----------" << std::endl;
	RapidJson rapid;

	std::cout << std::endl;
	if (rapid.doesDomKeepOrder()) {
		std::cout << "passed" << std::endl;
	} else {
		std::cout << "failed" << std::endl;
	}

	std::cout << std::endl;
	if (rapid.doesSaxKeepOrder()) {
		std::cout << "passed" << std::endl;
	} else {
		std::cout << "failed" << std::endl;
	}
	
	Performance::FLAT_TEXT_FILE_PATH = "../sample/json_flat_1mb.json";
	std::cout << std::endl;
	std::cout << "flat  : " << rapid.parseFlatText().count() << " (ns)" << std::endl;

	Performance::NESTED_TEXT_FILE_PATH = "../sample/json_nested_1mb.json";
	std::cout << std::endl;
	std::cout << "nested: " << rapid.parseNestedText().count() << " (ns)" << std::endl;
	
	std::cout << std::endl;
	std::cout << "---------- Nlohmann JSON ----------" << std::endl;
	Nlohmann nlohmann;

	std::cout << std::endl;
	if (nlohmann.doesDomKeepOrder()) {
		std::cout << "passed" << std::endl;
	} else {
		std::cout << "failed" << std::endl;
	}

	std::cout << std::endl;
	if (nlohmann.doesSaxKeepOrder()) {
		std::cout << "passed" << std::endl;
	} else {
		std::cout << "failed" << std::endl;
	}

	return 0;
}

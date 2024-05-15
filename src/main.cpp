#include <version.h>
#include <iostream>

#include <impl/rapidjson.h>

using namespace jcbm;

int main(int argc, char** argv) {
	std::cout << "version: " << Version::full << std::endl;
	
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

	return 0;
}

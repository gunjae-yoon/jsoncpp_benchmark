#include <version.h>
#include <iostream>

using namespace jcbm;

int main(int argc, char** argv) {
	std::cout << "version: " << Version::full << std::endl;
	return 0;
}

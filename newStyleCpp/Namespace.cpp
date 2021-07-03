#include "Namespace.h"

bool NamespaceClz::test() {
	Api();
	namespace namespace2 = NS;
	using namespace2::Api;
	Api();
	::Api();

	return true;
}

void NS::Version1::Api() {
	std::cout << "hello version1.api" << std::endl;
}

void NS::Version2::Api() {
	std::cout << "hello version2.api" << std::endl;
}

void ::Api() {
	std::cout << "hello global.api" << std::endl;
}
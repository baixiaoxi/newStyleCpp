#include "FString.h"

using namespace std::string_literals;

bool FString::test() {

	std::string str1 = "hello world"s;
	auto str2 = u8"hello world"s;
	auto str3 = u"hello world"s;

	std::cout << "typeid(str1) = " << typeid(str1).name() << std::endl;
	std::cout << "typeid(str2) = " << typeid(str2).name() << std::endl;
	std::cout << "typeid(str3) = " << typeid(str3).name() << std::endl;

	return true;
}
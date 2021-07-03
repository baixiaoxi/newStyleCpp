#include "Template.h"

bool Template::test() {
	std::vector<char> icVec;
	func1<char>(icVec);

	std::vector<int> intVec = { 1, 2 };
	std::vector<char> charVec = { 1, 2 };
	std::vector<long> longVec = { 1, 2 };
	func2<int, char, long>(intVec, charVec, longVec);

	print("hello", 1, 'c', false);

	return true;
}
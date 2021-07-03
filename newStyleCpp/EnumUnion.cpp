#include "EnumUnion.h"

bool EnumUnion::EnumUnion::test() {
	f(E{ 0 });
	byte i{ 42 };
	byte j = byte{ 42 };

	abc = 5;
	std::cout << "abc = " << abc << std::endl;
	std::cout << "efg = " << efg << std::endl;

	MyVariant mv;

	return true;
}
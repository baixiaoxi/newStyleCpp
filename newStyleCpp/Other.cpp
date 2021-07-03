#include "Other.h"

bool Other::test() {
	int i = 13;
	auto neg = !i;
	auto neg2 = !!i;

	std::cout << "typeid(!int) = " << typeid(neg).name() << ", value = " << neg << std::endl;
	std::cout << "typeid(!!int) = " << typeid(neg2).name() << ", value = " << neg2 << std::endl;

	return true;
}


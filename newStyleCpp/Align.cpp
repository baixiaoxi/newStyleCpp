#include "Align.h"
#include <iostream>

bool Align::test() {
	std::cout << alignof(Bar) << std::endl;

	return true;
}
#include "UtilityTest.h"
#include <utility>

namespace UtilityTest
{
	// exchange
	struct C
	{
		int i;
	};
	void exchangeTest()
	{
		C c1{ 1 };
		C c2{ 2 };
		C result = std::exchange(c1, c2);
		std::cout << "The old value of c1 is: " << result.i << std::endl;
		std::cout << "The new value of c1 after exchange is: " << c1.i << std::endl;
	}
	// get
	void getTest()
	{
		typedef std::pair<int, double> MyPair;
		MyPair c0(9, 3.14);
		// get elements by index
		std::cout << " " << std::get<0>(c0);
		std::cout << " " << std::get<1>(c0) << std::endl;
		// get elements by type (C++14)
		MyPair c1(1, 0.27);
		std::cout << " " << std::get<int>(c1);
		std::cout << " " << std::get<double>(c1) << std::endl;

	}

	bool UtilityTest::test() {
		exchangeTest();
		getTest();

		return true;
	}
}
#include "RandomTest.h"
#include <random>

namespace RandomTest
{
	using namespace std;

	bool RandomTest::test()
	{
		random_device rd;
		mt19937 gen(rd());

		for (int i = 0; i < 5; ++i)
		{
			cout << gen() << " ";
		}

		cout << endl;

		return true;
	}
}
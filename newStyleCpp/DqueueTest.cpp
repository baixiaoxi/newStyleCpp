#include "DqueueTest.h"
#include <deque>

namespace DqueueTest
{
	bool DqueueTest::test()
	{
		using namespace std;
		deque<int> c1, c2;
		c1.push_back(1);
		c2.push_back(2);

		if (c1 != c2)
			cout << "The deques are not equal." << endl;
		else
			cout << "The deques are equal." << endl;

		auto result = c1 < c2;
		result = c1 <= c2;
		result = c1 == c2;
		result = c1 > c2;
		result = c1 >= c2;

		return true;
	}
}
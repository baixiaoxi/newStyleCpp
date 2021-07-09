#include "ListTest.h"
#include <list>

namespace ListTest
{
	using namespace std;

	bool ListTest::test()
	{
		list<int> c1, c2;
		list<int>::const_iterator cIter;

		c1.push_back(10);
		c1.push_back(20);
		c1.assign(7, 4);

		return true;
	}
}
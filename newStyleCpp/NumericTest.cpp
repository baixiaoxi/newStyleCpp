#include "NumericTest.h"
#include <numeric>
#include <vector>

namespace NumericTest
{
	using namespace std;

	bool NumericTest::test()
	{
		vector<int> v1, v2(20);
		vector<int>::iterator iter1, iter2;

		int i;
		for (i = 1; i < 21; i++)
		{
			v1.push_back(i);
		}
		int total = accumulate(v1.begin(), v1.end(), 0);

		return true;
	}
}
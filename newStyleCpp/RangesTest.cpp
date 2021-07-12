#include "RangesTest.h"
#include <ranges>
#include <vector>

namespace RangesTest
{
	using namespace std;

	bool RangesTest::test()
	{
		vector<int> input = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		auto output = input
			| views::filter([](const int n) { return n % 3 == 0; })
			| views::transform([](const int n) { return n * n; });

		return true;
	}
}
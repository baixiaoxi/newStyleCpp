#include "SpanTest.h"
#include <span>

namespace SpanTest
{
	using namespace std;

	void Show(span<int> someValues)
	{
		// show values in reverse
		for (auto rIt = someValues.rbegin(); rIt != someValues.rend(); ++rIt)
		{
			cout << *rIt;
		}

		// show a subspan
		for (auto& i : someValues.subspan(1, 2))
		{
			cout << i;
		}
	}

	bool SpanTest::test()
	{
		int numbers[]{ 0, 1, 2, 3, 4 };
		Show(numbers);

		int a[] = { 0, 1, 2 };
		span<int> mySpan(a);
		auto bytes = as_bytes(mySpan);
		auto bytes2 = as_writable_bytes(mySpan);

		return true;
	}
}
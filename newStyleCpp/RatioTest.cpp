#include "RatioTest.h"
#include <ratio>

namespace RatioTest
{
	using namespace std;

	bool RatioTest::test()
	{
		atto _atto;
		cout << _atto.num << "," << _atto.den << endl;

		return true;
	}
}
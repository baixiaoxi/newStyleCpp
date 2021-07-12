#include "RatioTest.h"
#include <ratio>

namespace RatioTest
{
	using namespace std;

	bool RatioTest::test()
	{
		ratio<1, 3> aa;
		cout << aa.num << ", " << aa.den << endl;
		// atto
		atto _atto;
		cout << _atto.num << "," << _atto.den << endl;
		// ratio_add
		auto bb = ratio_add<ratio<1, 3>, ratio<1, 6>>{};
		std::cout << "1/3 + 1/6 = " << bb.num << '/' << bb.den << '\n';

		return true;
	}
}
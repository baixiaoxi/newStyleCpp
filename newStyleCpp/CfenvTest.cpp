#pragma STDC FENV_ACCESS ON

#include "CfenvTest.h"
#include <cfenv>

namespace CfenvTest
{
	using namespace std;

	volatile double zero = 0.0;
	volatile double one = 1.0;
	bool CfenvTest::test()
	{
		feclearexcept(FE_ALL_EXCEPT);
		cout << "1.0/0.0 = " << 1.0 / zero << '\n';
		if (fetestexcept(FE_DIVBYZERO))
		{
			cout << "division by zero reported\n";
		}
		else
		{
			cout << "division by zero not reported\n";
		}

		feclearexcept(FE_ALL_EXCEPT);
		cout << "1.0/10 = " << one / 10 << '\n';

		if (fetestexcept(FE_INEXACT))
		{
			cout << "inexact result reported\n";
		}
		else
		{
			cout << "inexact result not reported\n";
		}

		feclearexcept(FE_ALL_EXCEPT);
		cout << "sqrt(-1) = " << sqrt(-1) << '\n';
		if (fetestexcept(FE_INVALID))
		{
			cout << "invalid result reported\n";
		}
		else
		{
			cout << "invalid result not reported\n";
		}

		return true;
	}
}
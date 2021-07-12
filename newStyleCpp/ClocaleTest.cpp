#include "ClocaleTest.h"
#include <clocale>

namespace ClocaleTest
{
	using namespace std;

	bool ClocaleTest::test()
	{
		// 1.setlocale
		setlocale(LC_ALL, "en_US.UTF-8");
		setlocale(LC_NUMERIC, "de_DE.UTF-8");
		setlocale(LC_TIME, "ja_JP.UTF-8");
		// 2.localeconv
		lconv* result = localeconv();
		cout << result->currency_symbol << result->thousands_sep << result->mon_decimal_point << endl;

		return true;
	}
}
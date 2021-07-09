#include "LocaleTest.h"
#include <locale>

namespace LocaleTest
{
	using namespace std;

	bool LocaleTest::test()
	{
		locale loc("German_Germany");
		bool result1 = isalnum('L', loc);

		return true;
	}
}
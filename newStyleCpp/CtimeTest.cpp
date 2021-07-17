#include "CtimeTest.h"
#include <ctime>

namespace CtimeTest
{
	using namespace std;

	bool CtimeTest::test()
	{
		time_t tt = 0;
		timespec ts;
		tm* tm = nullptr;
		char* ascti = nullptr;

		gmtime_s(tm, &tt);
		tt = mktime(tm);
		asctime_s(ascti, 55, tm);
		ctime_s(ascti, 55, &tt);

		return true;
	}
}
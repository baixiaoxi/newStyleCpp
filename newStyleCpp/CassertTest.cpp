#include "CassertTest.h"
#include <cassert>

namespace CassertTest
{
	using namespace std;

	bool CassertTest::test()
	{
		assert(1 == 2);

		return true;
	}
}
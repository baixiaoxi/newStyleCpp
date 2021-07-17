#include "CstddefTest.h"
#include <cstddef>

namespace CstddefTest
{
	using namespace std;

	bool CstddefTest::test()
	{
		ptrdiff_t pt;
		size_t st;
		max_align_t mat;
		nullptr_t nt;
		byte by{ 'c' };
		int cVal = to_integer<int>(by);

		return true;
	}
}
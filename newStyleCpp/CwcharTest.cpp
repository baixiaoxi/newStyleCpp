#include "CwcharTest.h"
#include <cwchar>

namespace CwcharTest
{
	using namespace std;

	bool CwcharTest::test()
	{
		int result;
		FILE* stream = nullptr;

		result = fwprintf(stream, L"%d");

		return true;
	}
}
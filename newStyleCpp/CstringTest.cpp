#include "CstringTest.h"
#include <cstring>

namespace CstringTest
{
	using namespace std;

	bool CstringTest::test()
	{
		string s1 = "str1";
		string s2 = "str2";
		strcmp(s1.c_str(), s2.c_str());

		return true;
	}
}
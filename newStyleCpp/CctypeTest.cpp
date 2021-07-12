#include "CctypeTest.h"
#include <cctype>

namespace CctypeTest
{
	using namespace std;

	bool CctypeTest::test()
	{
		isalnum('c');
		isalpha('c');
		isblank('c');
		iscntrl('c');
		isdigit('c');
		isgraph('c');
		islower('c');
		isprint('c');
		ispunct('c');
		isspace('c');
		isupper('c');
		isxdigit('c');
		tolower('c');
		toupper('c');

		return true;
	}
}
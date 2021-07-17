#include "CctypeTest.h"
#include <cctype>

namespace CctypeTest
{
	using namespace std;

	bool CctypeTest::test()
	{
		int result;
		result = isalnum('c');
		result = isalpha('c');
		result = isblank('c');
		result = iscntrl('c');
		result = isdigit('c');
		result = isgraph('c');
		result = islower('c');
		result = isprint('c');
		result = ispunct('c');
		result = isspace('c');
		result = isupper('c');
		result = isxdigit('c');
		result = tolower('c');
		result = toupper('c');

		return true;
	}
}
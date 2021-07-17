#include "CwctypeTest.h"
#include <cwctype>

namespace CwctypeTest
{
	using namespace std;

	bool CwctypeTest::test()
	{
		int result;
		const char* cchar = "hello world";

		result = iswalnum('c');
		result = iswalpha('c');
		result = iswblank('c');
		result = iswcntrl('c');
		result = iswdigit('c');
		result = iswgraph('c');
		result = iswlower('c');
		result = iswprint('c');
		result = iswpunct('c');
		result = iswspace('c');
		result = iswupper('c');
		result = iswxdigit('c');
		result = iswctype('c', 1);
		result = wctype(cchar);
		result = towlower('c');
		result = towupper('c');
		result = towctrans('c', 1);
		result = wctrans(cchar);

		return true;
	}
}
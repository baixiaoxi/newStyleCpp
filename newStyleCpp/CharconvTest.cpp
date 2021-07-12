#include "CharconvTest.h"
#include <charconv>
#include <stdio.h>
#include <system_error>

namespace CharconvTest
{
	using namespace std;
	template<typename T>
	void TestToChars(const T t)
	{
		static_assert(is_floating_point<T>::value);
		constexpr bool IsFloat = is_same_v<T, float>;
		char buf[100];
		constexpr size_t size = IsFloat ? 15 : 24;
		const to_chars_result res = to_chars(buf, buf + size, t, chars_format::general);
		if (res.ec == errc{})
		{
			printf("success: %.*s\n", static_cast<int>(res.ptr - buf), buf);
		}
		else
		{
			printf("Error: %d\n", static_cast<int>(res.ec));
		}
	}

	double TestFromChars(const string_view sv)
	{
		const char* const first = sv.data();
		const char* const last = first + sv.size();
		double dbl;

		const from_chars_result res = from_chars(first, last, dbl, chars_format::general);
		if (res.ec == errc{})
		{
			printf("success: %g\n", dbl);
		}
		else
		{
			printf("Error: %d\n", static_cast<int>(res.ec));
		}

		return dbl;
	}

	bool CharconvTest::test()
	{
		TestToChars(123.34);
		double dbl = TestFromChars("123.34");

		return true;
	}
}
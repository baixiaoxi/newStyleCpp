#include "ArrayTest.h"
#include <array>

namespace ArrayTest
{
	using namespace std;
	typedef array<int, 4> MyArray;

	bool ArrayTest::test()
	{
		MyArray c0{ 0, 1, 2, 3 };
		for (const auto& e : c0)
		{
			cout << " " << e;
		}
		cout << endl;
		cout << " " << get<1>(c0);
		MyArray c1 = { 4, 5, 6, 7 };
		c0.swap(c1);
		swap(c0, c1);
		for (MyArray::const_iterator it = c0.begin(); it != c0.end(); ++it)
		{
			cout << " " << *it;
		}
		cout << endl;
		for (const auto& it : c0)
		{
			MyArray::value_type val = it;
			cout << " " << val;
		}

		return true;
	}
}
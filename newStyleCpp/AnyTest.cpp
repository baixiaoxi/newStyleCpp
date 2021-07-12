#include "AnyTest.h"
#include <any>

namespace AnyTest
{
	using namespace std;

	bool AnyTest::test()
	{
		any anyVal = make_any<int>(1);
		int intVal = any_cast<int>(anyVal);
		cout << boolalpha << anyVal.has_value();
		swap(anyVal, anyVal);
		const type_info& ti = anyVal.type();
		anyVal.emplace<int>(5);
		anyVal.reset();

		return true;
	}
}
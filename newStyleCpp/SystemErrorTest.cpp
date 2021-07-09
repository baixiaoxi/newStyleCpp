#include "SystemErrorTest.h"
#include <system_error>
#include <cerrno>
#include <thread>

namespace SystemErrorTest
{
	using namespace std;

	bool SystemErrorTest::test()
	{
		// 1.code, what
		try {
			thread().detach();
		}
		catch (const system_error& e)
		{
			cout << "Caught system error with code " << e.code() << " meaning " << e.what() << endl;
		}
		// 2.generic_category
		error_condition econd = generic_category().default_error_condition(EDOM);
		cout << "Category: " << econd.category().name() << '\n'
			 << "Value: " << econd.value() << '\n'
			 << "Message: " << econd.message() << '\n';
		// 3.

		return true;
	}
}
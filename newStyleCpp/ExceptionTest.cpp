#include "ExceptionTest.h"
#include <exception>

namespace ExceptionTest
{
	using namespace std;

	void termfunction()
	{
		cout << "My terminate function called." << endl;
		abort();
	}

	bool ExceptionTest::test()
	{
		terminate_handler oldHandler = set_terminate(termfunction);
		terminate();

		return true;
	}
}
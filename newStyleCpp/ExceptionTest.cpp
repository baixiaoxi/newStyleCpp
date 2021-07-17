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
		exception_ptr ce = current_exception();
		exception ex;
		ce = make_exception_ptr(ex);
		rethrow_exception(ce);

		return true;
	}
}
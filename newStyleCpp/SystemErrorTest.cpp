#include "SystemErrorTest.h"
#include <system_error>
#include <cerrno>
#include <thread>

namespace SystemErrorTest
{
	using namespace std;

	enum class S {

	};

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
		const error_category& default_category = generic_category();
		error_condition econd = generic_category().default_error_condition(EDOM);
		cout << "Category: " << econd.category().name() << '\n'
			<< "Value: " << econd.value() << '\n'
			<< "Message: " << econd.message() << '\n';
		// 3.is_error_code_enum_v
		cout << boolalpha << is_error_code_enum_v<S> << "is error code enum" << endl;
		// 4.is_error_condition_enum_v
		cout << boolalpha << is_error_condition_enum_v<S> << "is error condition enum" << endl;
		// 5.make_error_code
		error_code ec = make_error_code(errc::connection_reset);
		// 6.make_error_condition
		error_condition ecn = make_error_condition(errc::address_in_use);
		// 7.system_category
		const error_category& sc = system_category();
		// 8.errc
		errc code = errc::address_in_use;
		// 9.default_error_condition
		error_condition ec2 = sc.default_error_condition(EDOM);
		// 10.equivalent
		bool bv = sc.equivalent(EDOM, ec2);
		// 11.message
		string msg = sc.message(EDOM);
		// 12.name
		const char* name = sc.name();
		// 13.default_error_condition
		error_condition dec = ec.default_error_condition();
		// 14.clear
		ec.clear();
		// 15.category
		const error_category& eca2 = ec.category();
		// 16.error_code
		error_code ec3 = error_code(EDOM, default_category);
		// 17.message
		string msg2 = ec3.message();
		// 18.value
		int val = ec3.value();
		// 19.error_condition
		error_condition ec4;
		ec4.assign(EDOM, default_category);
		ec4.category();
		ec4.clear();
		ec4.message();
		ec4.value();
		// 19.system_error

		return true;
	}
}
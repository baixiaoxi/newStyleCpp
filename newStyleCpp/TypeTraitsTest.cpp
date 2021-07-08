#include "TypeTraitsTest.h"

namespace TypeTraitsTest
{
	void is_copy_constructible_test();

	bool TypeTraitsTest::test()
	{
		is_copy_constructible_test();
		return true;
	}

	void is_copy_constructible_test()
	{
		struct Copyable
		{
			int val;
		};

		struct NotCopyable
		{
			NotCopyable(const NotCopyable&) = delete;
			int val;
		};
		std::cout << "is_copy_constructible<Copyable> == " << std::boolalpha << std::is_copy_constructible<Copyable>::value << std::endl;
		std::cout << "is_copy_constructible<NotCopyable> == " << std::boolalpha << std::is_copy_constructible<NotCopyable>::value << std::endl;
	}
}
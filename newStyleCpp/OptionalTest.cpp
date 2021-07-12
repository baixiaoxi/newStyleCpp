#include "OptionalTest.h"
#include <optional>

namespace OptionalTest
{
	using namespace std;

	bool OptionalTest::test()
	{
		optional<int> opt = make_optional<int>(1);
		bool result = opt.has_value();
		nullopt_t no = nullopt;

		return true;
	}
}
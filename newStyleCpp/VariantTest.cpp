#include "VariantTest.h"
#include <variant>
#include <assert.h>

namespace VariantTest
{
	using namespace std;

	bool VariantTest::test()
	{
		variant<int, float> v, w;
		v = 42;
		int i = get<int>(v);
		w = get<int>(v);
		w = get<0>(v);

		try
		{
			get<float>(w);
		}
		catch (const bad_variant_access& ex)
		{
			cout << ex.what() << '\n';
		}

		using namespace std::literals;
		variant<string> x("abc");
		x = "def";
		variant<string, void const*> y("abc");
		assert(holds_alternative<void const*>(y));
		y = "xyz"s;
		assert(holds_alternative<string>(y));

		auto tt = get_if<int>(&v);
		auto tt2 = get_if<0>(&v);
		auto pos = v.index();
		auto pos2 = variant_npos;

		cout << "variant_npos: " << variant_npos << endl;
		size_t variantSize = variant_size<variant<string, void const*>>::value;

		return true;
	}
}
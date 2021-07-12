#include "UtilityTest.h"
#include <utility>
#include <array>
#include <string_view>
#include <system_error>
#include <charconv>

namespace UtilityTest
{
	using namespace std;

	struct Default { int foo() const { return 1; } };
	struct NonDefault { NonDefault() = delete; int foo() const { return 1; } };
	struct C { int i; };

	template<typename T, T... ints>
	void print_sequence(integer_sequence<T, ints...> int_seq)
	{
		cout << "The sequence of size " << int_seq.size() << ": ";
		((cout << ints << ' '), ...);
		cout << '\n';
	}

	template<ranges::input_range R, typename Projection = std::identity>
	void print(string_view const rem, R&& r, Projection proj = {})
	{
		cout << rem << "{ ";
		for_each(r, [](const auto& o) {cout << o << ' '; }, proj);
		cout << "}\n";
	}

	bool UtilityTest::test() {
		// 1.as_const
		int inVal = 1;
		const int inVal2 = as_const(inVal);
		// 2.declval
		decltype(Default().foo()) n1 = 1;
		decltype(declval<NonDefault>().foo()) n2 = n1;
		// 3.exchange
		C c1{ 1 };
		C c2{ 2 };
		C result = exchange(c1, c2);
		// 4.forward
		// Restoring the rvalue - ness of an argument's original value to do overload resolution is known as perfect forwarding
		// 5.from_chars
		// 6.get
		typedef pair<int, double> MyPair;
		MyPair c0(9, 3.14);
		cout << " " << get<0>(c0);
		cout << " " << get<int>(c0);
		// 7.index_sequence
		auto is = integer_sequence<unsigned, 1, 2, 3>{};
		print_sequence(is);
		// 8.index_sequence_for
		auto is2 = index_sequence_for<int, double>{};
		// 9.make_index_sequence
		auto is3 = make_index_sequence<3>();
		print_sequence(is3);
		// 10.make_integer_sequence
		auto is4 = make_integer_sequence<unsigned, 3>();
		print_sequence(is4);
		// 11.make_pair
		pair<int, double> p = make_pair(1, 3.0);
		// 12.move
		// Unconditionally casts its argument to an rvalue reference
		int lvalue = 3;
		cout << "rvalue:" << move(lvalue) << endl;
		// 13.swap
		int s1 = 1, s2 = 2;
		swap(s1, s2);
		// 14.to_chars
		array<char, 10> strArr;
		if (auto [ptr, ec] = to_chars(strArr.data(), strArr.data() + strArr.size(), 55.0, chars_format::general); ec == errc())
		{
			cout << string_view(strArr.data(), ptr);
		}
		// 15.identity

		return true;
	}
}
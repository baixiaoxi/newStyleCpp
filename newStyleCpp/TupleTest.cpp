#include "TupleTest.h"
#include <tuple>
#include <map>
#include <array>

namespace TupleTest
{
	using namespace std;
	int add(int first, int second) { return first + second; }

	bool TupleTest::test()
	{
		tuple<int, double, string> tup(0, 1.42, "Call me Tuple");
		// 1.apply
		apply(add, make_tuple(1, 2));
		// 2.forward_as_tuple
		map<int, string> m;
		m.emplace(piecewise_construct, forward_as_tuple(10), forward_as_tuple(20, 'a'));
		cout << "m[10] = " << m[10] << '\n';
		// 3.get elements by index
		cout << " " << get<0>(tup);
		cout << " " << get<1>(tup);
		cout << " " << get<2>(tup) << endl;
		// 4.get elements by type
		cout << " " << get<int>(tup);
		cout << " " << get<double>(tup);
		cout << " " << get<string>(tup) << endl;
		// 5.make_from_tuple
		class _TmpStr
		{
		public:
			_TmpStr(int i, double d, string s) { }
		};
		_TmpStr ts = make_from_tuple<_TmpStr>(tup);// Construct an object of type T, using the elements of the tuple t as the arguments to the constructor
		// 6.make_tuple
		typedef tuple<int, double, int, double> Mytuple;
		Mytuple c0, c1(0, 1, 2, 3);
		c0 = make_tuple(4, 5, 6, 7);
		// 7.swap
		swap(c0, c1);
		// 8.tie
		int v4 = 4; double v5 = 5; int v6 = 6; double v7 = 7;
		tie(v4, v5, v6, v7) = c0;// Makes a tuple from element references
		// 9.tuple_cat
		int n = 5;
		auto tuleCat = tuple_cat(c0, make_tuple(1, 3.2), c1, tie(n));
		// 10.tuple_element_t
		auto tupleElementTypeName = typeid(tuple_element_t<1, Mytuple>).name();
		tuple_element_t<0, Mytuple> val1 = get<0>(c0);
		tuple_element_t<1, Mytuple> val2 = get<1>(c0);
		// 11.tuple_size_v
		auto tupleSize = tuple_size_v<Mytuple>;
		// 12.tuple_size
		cout << "tuple size = " << tuple_size<Mytuple>::value << endl;
		// 13.tuple_element
		typedef pair<int, double> MyPair;
		typedef array<int, 4> MyArray;
		MyArray ca0{ 0, 1, 2, 3 };
		MyPair cp0(0, 1.333);
		tuple_element<0, Mytuple>::type valp0 = get<0>(cp0);
		tuple_element<1, MyPair>::type valp1 = get<1>(cp0);
		tuple_element<0, MyArray>::type val = ca0.front();
		cout << get<0>(cp0) << endl;

		return true;
	}
}
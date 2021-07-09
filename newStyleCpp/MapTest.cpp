#include "MapTest.h"
#include <map>

namespace MapTest
{
	using namespace std;

	bool MapTest::test()
	{
		typedef map<char, int> Mymap;
		Mymap c1;
		c1.insert(Mymap::value_type('a', 1));
		c1.insert(Mymap::value_type('b', 2));
		cout << "c1.at('a') == " << c1.at('a') << endl;

		return true;
	}
}
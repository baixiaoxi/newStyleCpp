#include "SetTest.h"
#include <set>

namespace SetTest
{
	using namespace std;

	bool SetTest::test()
	{
		set<int> s1, s2, s3;
		set<int>::iterator s1_Iter;
		set<int>::const_iterator s1_cIter;
		// 1.swap
		s1.swap(s2);
		swap(s1, s3);
		// 2.insert
		int i;
		for (i = 0; i < 3; i++)
		{
			s1.insert(i);
			s2.insert(i * i);
			s3.insert(i);
		}
		// 3.begin
		s1_Iter = s1.begin();
		// 4.erase
		s1.erase(s1_Iter);
		// 5.cbegin
		s1_cIter = s1.cbegin();
		// 6.key_comp
		set<int>::key_compare comp = s1.key_comp();
		bool result = comp(1, 3);
		// 7.lower_bound
		set<int>::iterator it = s1.lower_bound(2);
		// 8.value_comp
		set<int>::value_compare vcomp = s1.value_comp();
		result = vcomp(1, 3);

		return true;
	}
}
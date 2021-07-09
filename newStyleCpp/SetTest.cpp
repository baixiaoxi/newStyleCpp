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
		int i;

		for (i = 0; i < 3; i++)
		{
			s1.insert(i);
			s2.insert(i * i);
			s3.insert(i);
		}

		s1_Iter = s1.begin();
		s1.erase(s1_Iter);
		s1_cIter = s1.cbegin();


		return true;
	}
}
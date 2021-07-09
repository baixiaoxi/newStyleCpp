#include "StackTest.h"
#include <stack>

namespace StackTest
{
	using namespace std;

	bool StackTest::test()
	{
		stack<int> s1, s2;
		s1.push(1);
		s1.push(2);

		if (s1.empty())
			cout << "The stack s1 is empty." << endl;
		else
			cout << "The stack s1 is not empty." << endl;

		stack<int>::size_type i;
		i = s1.size();
		i = s1.top();
		s1.pop();

		stack<int>::value_type AnInt;
		AnInt = 69;

		return true;
	}
}
#include "StackTest.h"
#include <stack>
#include <vector>

namespace StackTest
{
	using namespace std;

	bool StackTest::test()
	{
		stack<int> s1, s2;
		// 1.push
		s1.push(1);
		s1.push(2);
		// 2.empty
		if (s1.empty())
			cout << "The stack s1 is empty." << endl;
		else
			cout << "The stack s1 is not empty." << endl;
		// 3.size_type
		stack<int>::size_type i;
		// 4.size
		i = s1.size();
		// 5.top
		i = s1.top();
		// 7.pop
		s1.pop();
		stack<int>::value_type AnInt;
		AnInt = 69;
		// 8.container_type
		stack<int>::container_type ct;
		// 9.custom container type
		stack<int, vector<int>> s3;

		return true;
	}
}
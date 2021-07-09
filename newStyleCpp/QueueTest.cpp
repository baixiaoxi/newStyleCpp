#include "QueueTest.h"
#include <queue>
#include <list>

namespace QueueTest
{
	using namespace std;

	bool QueueTest::test()
	{
		queue<int, list<int>> q1;
		q1.push(1);
		auto result = q1.empty();
		q1.pop();
		q1.push(10);
		q1.push(20);
		// priority_queue
		priority_queue<int, deque<int>> q2;
		q2.push(5);
		q2.push(15);
		priority_queue<int>::size_type i;
		i = q2.size();

		return true;
	}
}
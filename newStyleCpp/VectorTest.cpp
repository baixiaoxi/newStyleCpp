#include "VectorTest.h"
#include <vector>

namespace VectorTest
{
	using namespace std;

	bool VectorTest::test()
	{
		// 1.vector
		vector<int> v1{ 1, 2, 3, 4 };
		v1.shrink_to_fit();
		v1.assign({ 3, 4, 5 });
		cout << "capacity: " << v1.capacity();

		// 2.vector<bool>
		vector<bool>  vb;
		vb.push_back(true);
		vb.push_back(false);
		vb.push_back(true);

		vector<bool>::reference eref = vb[0];
		auto eref2 = vb[1];
		eref.flip();
		swap(eref, eref2);

		return true;
	}
}
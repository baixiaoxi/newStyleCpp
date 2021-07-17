#include "BitsetTest.h"
#include <bitset>

namespace BitsetTest
{
	using namespace std;

	bool BitsetTest::test()
	{
		bitset<5> myBitSet;
		myBitSet.set(3, true);
		myBitSet = myBitSet & myBitSet;
		bitset<5>::reference secondBit = myBitSet[1];
		secondBit.flip();
		myBitSet.flip();
		myBitSet.test(1);
		myBitSet.size();
		cout << boolalpha << myBitSet.any() << myBitSet.all() << myBitSet.count() << secondBit << endl;
		myBitSet.reset();

		return true;
	}
}
#include "BitTest.h"
#include <bit>
#include <bitset>

namespace BitTest
{
	using namespace std;

	bool BitTest::test()
	{
		float f = numeric_limits<float>::infinity();
		int i = bit_cast<int>(f);
		cout << "float f = " << hex << f << "\nbit_cast<int>(f) = " << hex << i << '\n';
		for (auto i = 0u; i < 6u; ++i)
		{
			auto nextClosetPowerOf2 = bit_ceil(i);
			auto previousPowerOf2 = bit_floor(i);
			cout << "\nbit_ceil(0b" << bitset<4>(i) << ") = " << "0b" << bitset<4>(nextClosetPowerOf2);
			cout << "\nbit_floor(0b" << bitset<4>(i) << ") = 0b" << bitset<4>(previousPowerOf2);
		}

		bit_width(5u);
		countl_zero(5u);
		countl_one(5u);
		countr_zero(5u);
		countr_one(5u);
		has_single_bit(5u);
		popcount(5u);
		rotl(5u, 1);
		rotr(5u, 1);

		return true;
	}
}
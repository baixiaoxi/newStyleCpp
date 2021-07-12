#include "ValarrayTest.h"
#include <valarray>

namespace ValarrayTest
{
	using namespace std;

	bool ValarrayTest::test()
	{
		// 1.function
		valarray arr1 = { 1, 2, 3, 4, -6 };
		arr1 = abs(arr1);
		arr1.apply([](int n) { return n * 2; });
		arr1 = arr1.cshift(4);// A positive parameter shifts elements right
		// arr1.free();
		arr1.max();
		arr1.min();
		arr1.resize(16, 10);
		arr1.size();
		arr1.shift(3);
		arr1.sum();
		arr1.swap(arr1);
		valarray<int>::value_type Right = 10;
		// 2.gslice class
		int i;
		valarray<int> va(20), vaResult;
		for (i = 0; i < 20; ++i)
		{
			va[i] = i;
		}
		valarray<size_t> Len(2), Stride(2);
		Len[0] = 4;
		Len[1] = 4;
		Stride[0] = 7;
		Stride[1] = 4;
		gslice vaGSlice(0, Len, Stride);
		vaResult = va[vaGSlice];
		for (i = 0; i < 8; ++i)
		{
			cout << " " << vaResult[i];
		}
		const valarray<size_t> size = vaGSlice.size();
		size_t vaGSstart = vaGSlice.start();
		const valarray<size_t> strideGS = vaGSlice.stride();
		// 3.gslice_array
		const size_t lv[] = { 2, 3 };
		const size_t dv[] = { 7, 2 };
		const valarray<size_t> len(lv, 2), str(dv, 2);
		gslice_array<int> result1 = va[gslice(3, len, str)]; // selects elements with indices 3, 5, 7, 10, 12, 14
		// 4.indirect_array
		valarray<size_t> indx(3);
		indx[0] = 2;
		indx[1] = 6;
		indx[2] = 6;
		indirect_array<int> ia = va[indx];
		ia = 10;// Select 2nd, 4th & 6th elements and assign a value of 10 to them
		// 5.mask_array
		mask_array<int> ma = va[va > 3];
		ma = 10;// Use masked subsets to assign a value of 10  to all elements grrater than 3 in value
		// 6.slice/slice_array
		slice vaSlice(3, 6, 3);
		slice_array<int> sa = va[vaSlice];
		cout << vaSlice.start() << vaSlice.size() << vaSlice.stride() << endl;
		// 7.valarray<bool>
		valarray<int> vaL(10), vaR(10);
		valarray<bool> vaBool(10);
		for (i = 0; i < 10; i += 2)
			vaL[i] = -i;
		for (i = 1; i < 10; i += 2)
			vaL[i] = i;
		for (i = 0; i < 10; i++)
			vaR[i] = i;
		vaBool = vaL < vaR;//valarray<bool>

		return true;
	}
}
#include "AlgorithmTest.h"
#include <algorithm>
#include <list>
#include <iostream>

namespace AlgorithmTest
{
	bool twice(int elem1, int elem2)
	{
		return elem1 * 2 == elem2;
	}

	void adjacent_find_test()
	{
		using namespace std;
		list<int> L;
		list<int>::iterator Iter;
		list<int>::iterator result1, result2;

		L.push_back(50);
		L.push_back(40);
		L.push_back(10);
		L.push_back(20);
		L.push_back(20);

		cout << "L = ( ";
		for (Iter = L.begin(); Iter != L.end(); Iter++)
			cout << *Iter << " ";
		cout << ")" << endl;
		result1 = adjacent_find(L.begin(), L.end());
		if (result1 == L.end())
			cout << "There are not two adjacent elements that are equal." << endl;
		else
			cout << "There are two adjacent elements that are equal.\n" << *(result1) << "." << endl;
		result2 = adjacent_find(L.begin(), L.end(), twice);
		if (result2 == L.end())
			cout << "There are not two adjacent elements where the second is twice the first." << endl;
		else
			cout << "There are two adjacent elements where the second is twice the first.\n"
			<< "They have value of " << *(result2++) << " & " << *result2 << "." << endl;
	}

	bool AlgorithmTest::test()
	{
		adjacent_find_test();

		return true;
	}
}
#include "StdexceptTest.h"
#include <stdexcept>
#include <bitset>
#include <vector>

namespace StdexceptTest
{
	using namespace std;

	/*template<class  T>
	class stingyallocator : public allocator<T>
	{
	public:
		template <class U>
		struct rebind { typedef stingyallocator<U> other; };
		_SIZT max_size() const
		{
			return 10;
		};

	};*/

	bool StdexceptTest::test()
	{
		// 1.domain_error
		try
		{
			throw domain_error("Your domain is in error!");
		}
		catch (exception& e)
		{
			cerr << "Caught: " << e.what() << endl;
			cerr << "Type: " << typeid(e).name() << endl;
		}
		// 2.invalid_argument
		try
		{
			bitset< 32 > bitset(string("11001010101100001b100101010110000"));
		}
		catch (exception& e)
		{
			cerr << "Caught " << e.what() << endl;
			cerr << "Type " << typeid(e).name() << endl;
		}
		// 3.length_error
		try
		{
			// vector<int, stingyallocator<int>> myv;
			vector<int> myv;
			for (int i = 0; i < 11; i++) myv.push_back(i);
		}
		catch (exception& e)
		{
			cerr << "Caught " << e.what() << endl;
			cerr << "Type " << typeid(e).name() << endl;
		};
		// 4.logic_error
		try
		{
			throw logic_error("logic error");
		}
		catch (exception& e)
		{
			cerr << "Caught: " << e.what() << endl;
			cerr << "Type: " << typeid(e).name() << endl;
		};
		// 5.out_of_range 
		try
		{
			string str("Micro");
			string rstr("soft");
			str.append(rstr, 5, 3);
			cout << str << endl;
		}
		catch (exception& e) {
			cerr << "Caught: " << e.what() << endl;
		};
		// 6.overflow_error
		try
		{
			bitset< 33 > bitset;
			bitset[32] = 1;
			bitset[0] = 1;
			unsigned long x = bitset.to_ulong();
		}
		catch (exception& e)
		{
			cerr << "Caught " << e.what() << endl;
			cerr << "Type " << typeid(e).name() << endl;
		};
		// 7.range_error
		try
		{
			throw range_error("The range is in error!");
		}
		catch (range_error& e)
		{
			cerr << "Caught: " << e.what() << endl;
			cerr << "Type: " << typeid(e).name() << endl;
		};
		// 8.runtime_error
		try
		{
			locale loc("test");
		}
		catch (exception& e)
		{
			cerr << "Caught " << e.what() << endl;
			cerr << "Type " << typeid(e).name() << endl;
		};
		// 9.underflow_error 
		try
		{
			throw underflow_error("The number's a bit small, captain!");
		}
		catch (exception& e) {
			cerr << "Caught: " << e.what() << endl;
			cerr << "Type: " << typeid(e).name() << endl;
		};

		return true;
	}
}
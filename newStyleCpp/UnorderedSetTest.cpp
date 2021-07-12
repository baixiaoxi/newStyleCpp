#include "UnorderedSetTest.h"
#include <unordered_set>

namespace UnorderedSetTest
{
	using namespace std;
	typedef unordered_set<char> Myset;
	typedef unordered_multiset<char> Mymultiset;
	typedef allocator<pair<const char, int>> Myalloc;

	bool UnorderedSetTest::test()
	{
		// 1.unordered_set
		Myset c1;
		Myset::allocator_type al = c1.get_allocator();
		Myset::hasher  hfn = c1.hash_function();
		c1.insert('a');
		c1.insert('b');
		c1.insert('c');

		for (Myset::const_iterator it = c1.begin(); it != c1.end(); ++it)
			cout << "[" << *it << "]";
		cout << endl;

		Myset c2;
		c2.insert('d');
		c2.insert('e');
		c2.insert('f');
		c1.swap(c2);

		for (Myset::const_iterator it = c1.begin(); it != c1.end(); ++it)
			cout << " [" << *it << "]";
		cout << endl;

		// 2.unordered_multiset
		Mymultiset cm1;
		cm1.insert('a');
		cm1.insert('b');
		cm1.insert('c');
		cm1.insert('c');

		Mymultiset cm2;
		cm2.insert('d');
		cm2.insert('e');
		cm2.insert('f');
		cm2.insert('f');

		cm1.swap(cm2);

		Mymultiset::size_type bucketId = cm1.bucket(1);
		Mymultiset::size_type bucketSize = cm1.bucket_size(bucketId);
		Mymultiset::size_type bucketCount = cm1.bucket_count();
		cout << "count(1) == " << cm1.count(1) << endl;
		cm1.emplace(5);
		cm1.emplace_hint(cm1.cbegin(), 6);
		auto isEmpty = cm1.empty();
		pair<Mymultiset::iterator, Mymultiset::iterator> pair1 = cm1.equal_range(5);
		cm1.find(5);
		Mymultiset::allocator_type cmalloc = cm1.get_allocator();
		Mymultiset::hasher cmhfn = cm1.hash_function();
		cout << "hfn(1) == " << cmhfn(1) << endl;
		Mymultiset::key_equal cmpfn = cm1.key_eq();
		cout << "cmpfn(1, 1) == " << boolalpha << cmpfn(1, 1) << endl;
		Mymultiset::key_type key = 1;
		Mymultiset::value_type value = 1;
		cm1.insert(value);
		cout << "load_factor() == " << cm1.load_factor() << endl;
		cout << "max_load_factor() == " << cm1.max_load_factor() << endl;
		Mymultiset::local_iterator lit = cm1.begin(cm1.bucket(1));// inspect bucket containing 1
		cout << "[" << *lit << "]" << endl;
		for (Mymultiset::iterator it = cm1.begin(); it != cm1.end(); ++it)
		{
			Mymultiset::key_type key = *it;
			Mymultiset::pointer p = &key;
			Mymultiset::reference ref = key;
			cout << "[" << *p << "]";
		}

		cm1.rehash(10);// rebuilds the hash table

		return true;
	}
}
#include "UnorderedMapTest.h"
#include <unordered_map>

namespace UnorderedMapTest
{
	using namespace std;

	typedef unordered_map<char, int> Mymap;
	typedef unordered_multimap<char, int> Mymultimap;
	typedef allocator<pair<const char, int>> Myalloc;

	bool UnorderedMapTest::test()
	{
		// 1.unordered_map
		Mymap c1;
		c1.insert(Mymap::value_type('a', 1));
		c1.insert(Mymap::value_type('b', 2));
		c1.insert(make_pair('c', 3));

		Mymap c2;
		c2.insert(Mymap::value_type('d', 4));
		c2.insert(Mymap::value_type('e', 5));
		c2.insert(make_pair('f', 6));

		cout << boolalpha << (c1 == c2);

		swap(c1, c2);
		c1.swap(c2);

		Mymap::allocator_type al = c1.get_allocator();
		cout << "al == std::allocator() is " << boolalpha << (al == Myalloc()) << endl;

		cout << "c1.at('a') == " << c1.at('a') << endl;
		Mymap::size_type bucketId = c1.bucket('a');
		Mymap::size_type bucketCount = c1.bucket_count();
		Mymap::size_type bucketSize = c1.bucket_size(bucketId);

		Mymap::const_local_iterator lit = c1.begin(c1.bucket('a'));
		cout << "[" << lit->first << ", " << lit->second << "]";
		auto [iterator, success] = c1.emplace('c', 1);
		pair<Mymap::iterator, Mymap::iterator> ranges = c1.equal_range('a');
		Mymap::size_type max_bucket_count = c1.max_bucket_count();
		Mymap::size_type max_size = c1.max_size();
		Mymap::size_type max_load_factor = c1.max_load_factor();
		// 2.unordered_multimap
		// The object orders the sequence it controls by calling two stored objects, a comparison function object of 
		// type unordered_multimap::key_equal and a hash function object of type unordered_multimap::hasher
		Mymultimap mc1;
		mc1.insert(make_pair('a', 1));
		mc1.insert(Mymultimap::value_type('b', 2));
		mc1.insert(make_pair('c', 3));
		mc1.rehash(100);
		Mymultimap::size_type mbucketCount = mc1.bucket_count();
		Mymultimap::key_equal cmpfn = mc1.key_eq();
		cout << "cmpfn('a', 'a' == " << boolalpha << cmpfn('a', 'a') << endl;
		Mymultimap::key_type key = 'a';
		Mymultimap::mapped_type mapped = 4;
		Mymultimap::value_type val = Mymultimap::value_type(key, mapped);
		mc1.insert(val);

		return true;
	}
}
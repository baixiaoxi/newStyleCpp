#include "StringTest.h"
#include <string>
#include <vector>

namespace StringTest
{
	using namespace std;

	bool StringTest::test()
	{
		string str;
		vector<string> v1;
		cout << "Enter a setence, press ENTER between setences. (Ctrl-Z to stop): " << endl;
		while (getline(cin, str)) {
			v1.push_back(str);
		}

		cout << "The following input was stored with newline delimiter: " << endl;
		for (const auto& p : v1) {
			cout << p << endl;
		}
		cin.clear();
		vector<string> v2;
		while (getline(cin, str, ' ')) {
			v2.push_back(str);
		}
		cout << "The following input was stored with whitespace as delimiter: " << endl;
		for (const auto& p : v2) {
			cout << p << endl;
		}
		// 2.swap
		string s1("Tweedledee");
		string s2("Tweedledum");
		swap(s1, s2);
		// 3.to_string
		string s3 = to_string(123);
		// 4.operator+
		string s4 = s1 + s2;
		// 5.allocator
		basic_string<char>::allocator_type xchar = s1.get_allocator();
		// 6.append
		s1.append("hello");
		// 7.assign
		s1.assign(s2, 3);
		// 8.at
		s1.at(1);
		// 9.back
		s1.back();
		// 10.c_str
		auto cStr0 = s1.c_str();
		// 11.shrink_to_fit
		s1.shrink_to_fit();
		// char_traits
		char ChTo = 't';
		const char ChFrom = 'f';
		char_traits<char>::assign(ChTo, ChFrom);
		char_traits<char>::char_type cs1[] = "abcd-1234-abcd";
		char_traits<char>::char_type* result1;
		result1 = char_traits<char>::assign(cs1, 4, 'f');
		const char_traits<char>::char_type* cs2 = "CAB";
		const char_traits<char>::char_type* cs3 = "ABC";
		int comp1;
		comp1 = char_traits<char>::compare(cs2, cs3, 2);
		char_traits<char>::int_type int2 = char_traits<char>::eof();

		return true;
	}
}
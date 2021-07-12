#include "StringViewTest.h"
#include <string_view>
#include <string>

namespace StringViewTest
{
	using namespace std;

	void f(wstring_view wv) {}

	bool StringViewTest::test()
	{
		// 1.wstring_view
		const wstring& s{ L"Helo" };
		f(s);

		const wchar_t* ns = L"Hello";
		f(ns);

		const wchar_t* cs{ L"Hello" };
		size_t len{ 5 };
		f({ cs, len });

		// 2.hash
		string_view sv{ "Hello world" };
		string s2{ "Hello world" };
		cout << boolalpha << (hash<string_view>{}(sv) == hash<string>{}(s2));

		// 3.at
		string_view str1("Hello world");
		string_view::const_reference refStr2 = str1.at(8);
		// 4.back
		cout << str1.size();
		cout << str1.back() << endl;
		// 5.compare
		string_view sv_A("CAB");
		string_view sv_B("CAB");
		int comp1 = sv_A.compare(sv_B);
		// 6.ends_with
		str1.ends_with('g');
		str1.ends_with("efg");
		basic_string_view<char> str2 = "efg";
		str1.ends_with(str2);
		// 7.remove_prefix
		basic_string_view<char> str3 = "hello world";
		str3.remove_prefix(1);

		return true;
	}
}
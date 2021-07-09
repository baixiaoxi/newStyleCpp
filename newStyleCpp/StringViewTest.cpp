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

		return true;
	}
}
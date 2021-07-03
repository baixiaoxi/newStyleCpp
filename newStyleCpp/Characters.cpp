#include "Characters.h"

using namespace std::string_literals;
using namespace std;

bool Characters::test() {
	auto c0 = 'A';// char
	auto c1 = u8'A';// char
	auto c2 = L'A';// wchar_t
	auto c3 = u'A';// char16_t
	auto c4 = U'A';// char32_t

	// Multicharacter literals
	auto m0 = 'abcd'; // int, value 0x61626364

	// String literals
	auto s0 = "hello"; // const char*
	auto s1 = u8"hello"; // const char*, encoded as UTF-8
	auto s2 = L"hello"; // const wchar_t*
	auto s3 = u"hello"; // const char16_t*, encoded as UTF-16
	auto s4 = U"hello"; // const char32_t*, encoded as UTF-32

	// Raw string literals containing unescaped \ and "
	auto R0 = R"("Hello \ world")"; // const char*
	auto R1 = u8R"("Hello \ world")"; // const char*, encoded as UTF-8
	auto R2 = LR"("Hello \ world")"; // const wchar_t*
	auto R3 = uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16
	auto R4 = UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32

	// Combining string literals with standard s-suffix
	auto S0 = "hello"s; // std::string
	auto S1 = u8"hello"s; // std::string
	auto S2 = L"hello"s; // std::wstring
	auto S3 = u"hello"s; // std::u16string
	auto S4 = U"hello"s; // std::u32string

	// Combining raw string literals with standard s-suffix
	auto S5 = R"("Hello \ world")"s; // std::string from a raw const char*
	auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char*, encoded as UTF-8
	auto S7 = LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*
	auto S8 = uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16
	auto S9 = UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32

	char newline = '\n';
	char tab = '\t';
	char backspace = '\b';
	char backslash = '\\';
	char nullChar = '\0';

	cout << "Newline character: " << newline << "ending" << endl;
	cout << "Tab character: " << tab << "ending" << endl;
	cout << "Backspace character: " << backspace << "ending" << endl;
	cout << "Backslash character: " << backslash << "ending" << endl;
	cout << "Null character: " << nullChar << "ending" << endl;

	char c00 = 'abcd';    // C4305, C4309, truncates to 'd'
	wchar_t w0 = 'abcd';    // C4305, C4309, truncates to '\x6364'
	int i0 = 'abcd';    // 0x61626364

	char c30 = '\009';   // '9'
	char c40 = '\089';   // C4305, C4309, truncates to '9'
	char c5 = '\qrs';   // C4129, C4305, C4309, truncates to 's'

	char c6 = '\x0050'; // 'P'
	char c7 = '\x0pqr'; // C4305, C4309, truncates to 'r'

	wchar_t w1 = L'\100';   // L'@'
	wchar_t w2 = L'\1000';  // C4066 L'@', 0 ignored
	wchar_t w3 = L'\009';   // C4066 L'\0', 9 ignored
	wchar_t w4 = L'\089';   // C4066 L'\0', 89 ignored
	wchar_t w5 = L'\qrs';   // C4129, C4066 L'q' escape, rs ignored
	wchar_t w6 = L'\x0050'; // L'P'
	wchar_t w7 = L'\x0pqr'; // C4066 L'\0', pqr ignored

	char u1 = 'A';          // 'A'
	char u2 = '\101';       // octal, 'A'
	char u3 = '\x41';       // hexadecimal, 'A'
	char u4 = '\u0041';     // \u UCN 'A'
	char u5 = '\U00000041'; // \U UCN 'A'

	const char* narrow = "abcd";

	// represents the string: yes\no
	const char* escaped = "yes\\no";

	const char* str1 = u8"Hello World";
	const char* str2 = u8"\U0001F607 is O:-)";

	const wchar_t* wide = L"zyxw";
	const wchar_t* newline0 = L"hello\ngoodbye";

	auto s30 = u"hello"; // const char16_t*
	auto s40 = U"hello"; // const char32_t*

	// represents the string: An unescaped \ character
	const char* raw_narrow = R"(An unescaped \ character)";
	const wchar_t* raw_wide = LR"(An unescaped \ character)";
	const char* raw_utf8 = u8R"(An unescaped \ character)";
	const char16_t* raw_utf16 = uR"(An unescaped \ character)";
	const char32_t* raw_utf32 = UR"(An unescaped \ character)";

	const char* good_parens = R"xyz()")xyz";

	// represents the string: hello
	// goodbye
	const wchar_t* newlinem = LR"(hello
    goodbye)";

	//#include <string>
	//using namespace std::string_literals;
	string str{ "hello"s };
	string str20{ u8"Hello World" };
	wstring str3{ L"hello"s };
	u16string str4{ u"hello"s };
	u32string str5{ U"hello"s };

	u32string str6{ UR"(She said "hello.")"s };

	const wchar_t* str0 = L"Hello!";
	const size_t byteSize = (wcslen(str0) + 1) * sizeof(wchar_t);

	char strs[] = "12" "34";

	// ASCII smiling face
	const char* s11 = ":-)";
	// UTF-16 (on Windows) encoded WINKING FACE (U+1F609)
	const wchar_t* s21 = L"😉 = \U0001F609 is ;-)";
	// UTF-8  encoded SMILING FACE WITH HALO (U+1F607)
	const char* s31 = u8"😇 = \U0001F607 is O:-)";
	// UTF-16 encoded SMILING FACE WITH OPEN MOUTH (U+1F603)
	const char16_t* s41 = u"😃 = \U0001F603 is :-D";
	// UTF-32 encoded SMILING FACE WITH SUNGLASSES (U+1F60E)
	const char32_t* s51 = U"😎 = \U0001F60E is B-)";

	return true;
}
#include "RegexTest.h"
#include <regex>

namespace RegexTest
{
	using namespace std;

	bool RegexTest::test()
	{
		regex::value_type elem = 'x';
		regex::flag_type flag = regex::grep;
		cmatch cmat;

		regex rx0;
		cout << "match(\"abc\", \"\") == " << boolalpha << regex_match("abc", cmat, rx0, regex_constants::match_flag_type::format_default) << endl;
		regex rx1("abcd", regex::ECMAScript);
		cout << "match(\"abc\", \"abcd\") == " << boolalpha << regex_match("abc", rx1) << endl;

		regex rx2("abcd", 3);
		cout << "match(\"abc\", \"abc\") == " << boolalpha << regex_match("abc", rx2) << endl;

		regex rx3(rx2);
		cout << "match(\"abc\", \"abc\") == " << boolalpha << regex_match("abc", rx3) << endl;

		string str("abcd");
		regex rx4(str);
		cout << "match(string(\"abcd\"), \"abc\") == " << boolalpha << regex_match("abc", rx4) << endl;

		regex rx5(str.begin(), str.end() - 1);
		cout << "match(string(\"abc\"), \"abc\") == " << boolalpha << regex_match("abc", rx5) << endl;
		cout << endl;

		regex::flag_type flags = rx0.flags();

		// assignments
		rx0 = "abc";
		rx0 = rx1;
		rx0 = str;

		rx0.assign("abcd", regex::ECMAScript);
		rx0.assign("abcd", 3);
		rx0.assign(rx1);
		rx0.assign(str);
		rx0.assign(str.begin(), str.end() - 1);

		rx0.swap(rx1);

		// mark_count
		cout << "\"abc\" mark_count == " << regex("abc").mark_count() << endl;
		cout << "\"(abc)\" mark_count == " << regex("(abc)").mark_count() << endl;

		// locales
		regex::locale_type loc = rx0.imbue(locale());
		cout << "getloc == imbued == " << boolalpha << (loc == rx0.getloc()) << endl;

		// initializer_list
		regex rx6({ 'a', 'b', 'c' }, regex::ECMAScript);
		cout << "match(\"abc\") == " << boolalpha << regex_match("abc", rx6);
		cout << endl;

		// regex_error
		regex_error paren(regex_constants::error_paren);
		try
		{
			regex rx("(a");
		}
		catch (const regex_error& rerr)
		{
			cout << "regex error: " << (rerr.code() == paren.code() ? "unbalanced parentheses" : "") << endl;
		}
		catch (...)
		{
			cout << "unknown exception" << endl;
		}
		// regex_iterator
		typedef regex_iterator<const char*> Myiter;
		const char* pat = "axayaz";
		Myiter::regex_type rx("a");
		Myiter next(pat, pat + strlen(pat), rx);
		Myiter end;

		for (; next != end; ++next)
			cout << "match == " << next->str() << endl;

		// other members
		Myiter it1(pat, pat + strlen(pat), rx);
		Myiter it2(it1);
		next = it1;

		Myiter::iterator_category cat = forward_iterator_tag();
		Myiter::difference_type dif = -3;
		Myiter::value_type mr = *it1;
		Myiter::reference ref = mr;
		Myiter::pointer ptr = &ref;
		//

		return true;
	}
}
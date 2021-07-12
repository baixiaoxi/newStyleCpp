#define _SILENCE_CXX17_STRSTREAM_DEPRECATION_WARNING // strstream is deprecated

#include "StrstreamTest.h"
#include <strstream>

// Describes a stream buffer that controls the transmission of elements to and from a sequence of elements stored in a char array object
namespace StrstreamTest
{
	using namespace std;

	void report(strstream& x)
	{
		if (!x.good())
		{
			cout << "stream bad" << endl;
		}
		else
		{
			cout << "stream good" << endl;
		}
	}

	bool StrstreamTest::test()
	{
		strstream x;
		cout << "before freeze: ";
		report(x);
		// 1.str
		cout.write(x.rdbuf()->str(), 5) << endl;// Calling str freezes stream
		cout << "after freeze: ";
		report(x);
		// 2.<<
		x << "test1.5";
		cout << "after write to frozen stream: ";
		report(x);
		// 3.freeze
		x.rdbuf()->freeze(false);
		cout << "after unfreezing stream: ";
		report(x);
		// 4.clear
		x.clear();
		cout << "after clearing stream: ";
		report(x);
		// 5.rdbuf
		x << "test3";
		cout.write(x.rdbuf()->str(), 10) << endl;
		x.rdbuf()->freeze(false);
		// 6.pcount
		cout << x.rdbuf()->pcount() << endl;
		
		// istream->istrstream
		// ostream->ostrstream
		// iostream->strstream


		return true;
	}
}
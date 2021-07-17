#include "SstreamTest.h"
#include <sstream>

namespace SstreamTest
{
	using namespace std;

	bool SstreamTest::test()
	{
		basic_istringstream<char> bi;
		istringstream bi2;
		basic_ostringstream<char> bo;
		ostringstream bo2;
		basic_stringstream<char> bs;
		stringstream bs2;
		basic_stringbuf<char> bsf;

		return true;
	}
}
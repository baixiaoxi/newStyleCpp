#include "CstdlibTest.h"
#include <cstdlib>>

namespace CstdlibTest
{
	using namespace std;

	bool CstdlibTest::test()
	{
		int code;

		code = NULL;
		code = EXIT_FAILURE;
		code = EXIT_SUCCESS;
		code = RAND_MAX;
		code = MB_CUR_MAX;

		div_t dt;
		ldiv_t ldt;
		lldiv_t lldt;

		abort();
		atexit([]() {cout << "atexit"; });
		exit(EXIT_SUCCESS);
		quick_exit(EXIT_FAILURE);
		//char* env = getenv("env");
		void* ptr = calloc(55, 55);
		ptr = malloc(55);
		ptr = realloc(ptr, 77);
		free(ptr);
		double dval = atof("77");

		return true;
	}
}
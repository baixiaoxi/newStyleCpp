#include "CinttypesTest.h"
#include <cinttypes> // cstdint

namespace CinttypesTest
{
	using namespace std;

	bool CinttypesTest::test()
	{
		char buffer[80];
		intmax_t foo, bar;
		int64_t i64;
		printf("Please, enter a number: ");
		fgets(buffer, 80, stdin);
		foo = strtoimax(buffer, NULL, 10);
		printf("Thanks for entering %" PRIdMAX ".\n", foo);
		printf("Please, enter another number: ");
		scanf_s("%", SCNdMAX, &bar);
		printf("%" PRIdMAX " by %" PRIdMAX " is %" PRIdMAX, foo, bar, foo * bar);

		return true;
	}
}
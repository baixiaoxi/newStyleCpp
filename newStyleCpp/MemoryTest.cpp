#include "MemoryTest.h"
#include <memory>

namespace MemoryTest
{
	using namespace std;

	bool MemoryTest::test()
	{
		char buffer[256]; // for simplicity
		size_t alignment = alignment_of<int>::value;
		void* ptr = buffer;
		size_t space = sizeof(buffer); // Be sure this results in the true size of your buffer

		while (align(alignment, sizeof(int), ptr, space)) {
			// You now have storage the size of MyObj, starting at ptr, aligned on
			// int boundary. Use it here if you like, or save off the starting address
			// contained in ptr for later use.
			// ...
			// Last, move starting pointer and decrease available space before
			// the while loop restarts.
			ptr = reinterpret_cast<char*>(ptr) + sizeof(int);
			space -= sizeof(int);
		}

		return true;
	}
}
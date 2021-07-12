#include "AtomicTest.h"
#include <atomic>

namespace AtomicTest
{
	using namespace std;

	bool AtomicTest::test()
	{
		atomic<int> ai0 = ATOMIC_VAR_INIT(0);
		atomic<int> ai1(0);
		ai0.is_lock_free();
		int loadVal = ai0.load();
		ai0.store(loadVal);

		return true;
	}
}
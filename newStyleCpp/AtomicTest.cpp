#include "AtomicTest.h"
#include <atomic>

namespace AtomicTest
{
	using namespace std;

	bool AtomicTest::test()
	{
		int ival = 0;
		atomic<int> ai0 = ATOMIC_VAR_INIT(0);
		atomic<int> ai1(0);
		ai0.is_lock_free();
		int loadVal = ai0.load();
		ai0.store(loadVal);
		atomic_is_lock_free(&ai0);
		ai1.is_lock_free();

		atomic_char ac;
		atomic_int ai;
		atomic_long al;
		atomic_int8_t ai8;
		atomic_int_fast16_t aif16;

		ai.compare_exchange_strong(ival, 5, memory_order_acquire, memory_order_consume);
		ai.exchange(ai0);
		ai.fetch_add(8);
		ival = ai.fetch_and(8);
		ival = ai.fetch_or(8);
		ival = ai.fetch_sub(8);
		ival = ai.fetch_xor(8);

		atomic_flag flag;
		flag.clear();
		flag.test_and_set(memory_order_seq_cst);
		atomic_flag_clear(&flag);
		atomic_flag_test_and_set(&flag);

		return true;
	}
}
#include "SharedMutexTest.h"
#include <shared_mutex>
#include <mutex>
#include <chrono>

namespace SharedMutexTest
{
	using namespace std;

	bool SharedMutexTest::test()
	{
		// 1.shared_mutex
		shared_mutex sm;
		bool result = sm.try_lock();
		result = sm.try_lock_shared();
		sm.lock();
		sm.unlock();
		sm.lock_shared();
		sm.unlock_shared();

		// 2.shared_timed_mutex
		shared_timed_mutex stm;
		result = stm.try_lock_for(13ms);
		result = stm.try_lock_shared_until(chrono::system_clock::now() + 100ms);

		// 3.shared_lock
		mutex mu;
		// shared_lock sl(mu);

		return true;
	}
}
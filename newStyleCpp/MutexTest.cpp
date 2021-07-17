#include "MutexTest.h"
#include <mutex>

namespace MutexTest
{
	using namespace std;

	bool MutexTest::test()
	{
		// 1.mutex
		mutex mymutex;
		mymutex.lock();
		auto nht = mymutex.native_handle();
		mymutex.try_lock();
		mymutex.unlock();
		// 2.once_flag
		once_flag of;
		// 3.recursive_mutex
		recursive_mutex remutex;
		remutex.lock();
		remutex.try_lock();
		remutex.unlock();
		// 4.recursive_timed_mutex
		recursive_timed_mutex retimutex;
		retimutex.lock();
		retimutex.try_lock();
		retimutex.try_lock_for(chrono::duration{ 1ms });
		retimutex.try_lock_until(chrono::system_clock::now() + 5s);
		retimutex.unlock();
		// 5.timed_mutex
		timed_mutex timutex;
		timutex.lock();
		timutex.unlock();
		timutex.try_lock();
		timutex.try_lock_for(chrono::duration(1ms));
		timutex.try_lock_until(chrono::system_clock::now() + 5s);
		// 6.unique_lock
		unique_lock<timed_mutex> unilock;
		cout << typeid(unique_lock<timed_mutex>::mutex_type).name() << endl;
		unilock.lock();
		unique_lock<timed_mutex>::mutex_type* internalMutex = unilock.mutex();
		unilock.owns_lock();
		unilock.release();
		unilock.swap(unilock);
		unilock.try_lock();
		unilock.try_lock_for(chrono::duration(1s));
		unilock.try_lock_until(chrono::system_clock::now() + 5s);
		unilock.unlock();
		// 7.try_to_lock_t
		timed_mutex timmutex2;
		try_to_lock_t trylockt;
		unique_lock<timed_mutex> unilock2(timmutex2, trylockt);
		// 8.lock_guard
		lock_guard<mutex> lockguard(mymutex);
		cout << typeid(lock_guard<mutex>::mutex_type).name() << endl;
		// 9.adopt_lock_t
		recursive_mutex remutex3;
		adopt_lock_t adoptlockt;
		unique_lock<recursive_mutex> unilock3(remutex3, adoptlockt);
		// 10.defer_lock_t
		recursive_timed_mutex retimutex2;
		defer_lock_t deferlockt;
		unique_lock<recursive_timed_mutex> unilock4(retimutex2, deferlockt);

		return true;
	}
}
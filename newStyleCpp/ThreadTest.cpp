#include "ThreadTest.h"
#include <thread>
#include <chrono>

namespace ThreadTest
{
	using namespace std;
	// Thread objects can be moved but not copied.
	// Therefore, a thread of execution can be associated with only one thread object

	void foo()
	{
		// 1.sleep_for
		this_thread::sleep_for(chrono::seconds(1));
		// 2.sleep_until
		this_thread::sleep_until(chrono::steady_clock::now() + 2000ms);
		// 3.yield
		this_thread::yield();// Signals the operating system to run other threads, even if the current thread would ordinarily continue to run
	}

	bool ThreadTest::test()
	{
		thread t1(foo);
		thread t2(foo);

		// 1.get_id
		thread::id t1_id = t1.get_id();
		// 2.detach
		t1.detach();
		// 3.hardware_concurrency
		thread::hardware_concurrency();
		// 4.joinable
		bool joinable = t1.joinable();
		// 5.native_handle
		thread::native_handle_type nht = t1.native_handle();
		// 6.swap
		swap(t1, t2);
		// 7.join
		t1.join();
		t2.join();

		return true;
	}
}
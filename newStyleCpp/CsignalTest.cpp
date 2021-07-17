#include "CsignalTest.h"
#include <csignal>

namespace CsignalTest
{
	using namespace std;

	bool CsignalTest::test()
	{
		_crt_signal_t signal_t;
		signal_t = SIG_DFL;
		signal_t = SIG_ERR;
		signal_t = SIG_IGN;

		int signal_v;
		signal_v = SIGABRT;
		signal_v = SIGFPE;
		signal_v = SIGILL;
		signal_v = SIGINT;
		signal_v = SIGSEGV;
		signal_v = SIGTERM;

		_In_opt_ _crt_signal_t signalHandler = nullptr;
		signal(signal_v, signalHandler);
		raise(signal_v);

		return true;
	}
}
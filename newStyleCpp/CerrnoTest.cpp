#include "CerrnoTest.h"
#include <cerrno>

namespace CerrnoTest
{
	using namespace std;

	bool CerrnoTest::test()
	{
		// Error codes
		int errorCode;
		errorCode = EPERM;
		errorCode = ENOENT;
		errorCode = ESRCH;
		errorCode = EINTR;
		errorCode = EIO;
		errorCode = ENXIO;
		errorCode = E2BIG;
		errorCode = ENOEXEC;
		errorCode = EBADF;
		errorCode = ECHILD;
		errorCode = EAGAIN;
		errorCode = ENOMEM;
		errorCode = EACCES;
		errorCode = EFAULT;
		errorCode = EBUSY;
		errorCode = EEXIST;
		errorCode = EXDEV;
		errorCode = ENODEV;
		errorCode = ENOTDIR;
		errorCode = EISDIR;
		errorCode = ENFILE;
		errorCode = EMFILE;
		errorCode = ENOTTY;
		errorCode = EFBIG;
		errorCode = ENOSPC;
		errorCode = ESPIPE;
		errorCode = EROFS;
		errorCode = EMLINK;
		errorCode = EPIPE;
		errorCode = EDOM;
		errorCode = EDEADLK;
		errorCode = ENAMETOOLONG;
		errorCode = ENOLCK;
		errorCode = ENOSYS;
		errorCode = ENOTEMPTY;

		return true;
	}
}
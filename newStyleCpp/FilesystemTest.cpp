#include "FilesystemTest.h"
#include <filesystem>

namespace FilesystemTest
{
	using namespace std;
	using namespace std::filesystem;

	bool FilesystemTest::test()
	{
		path relativePath = "../folder";
		path basePath = "C:\\";
		path absolutePath = absolute(relativePath);
		path canonicalPath = canonical(relativePath);
		auto iteratorBegin = begin(absolutePath);
		auto iteratorEnd = end(absolutePath);
		for (; iteratorBegin != iteratorEnd; ++iteratorBegin)
		{
			cout << "current dir: " << *iteratorBegin;
		}

		return true;
	}
}
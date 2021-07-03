#include "OperatorClz.h"

bool OperatorClz::OperatorClz::test()
{
	IntVector v(10);
	int i;

	for (i = 0; i <= 10; ++i)
		v[i] = i;

	v[3] = v[9];
	for (i = 0; i <= 10; ++i)
		std::cout << "Element: [" << i << "] = " << v[i] << std::endl;

	return true;
}

OperatorClz::IntVector::IntVector(int cElements) {
	_iElements = new int[cElements];
	_iUpperBound = cElements;
}

int& OperatorClz::IntVector::operator[](int nSubscript) {
	static int iErr = -1;
	if (nSubscript >= 0 && nSubscript < _iUpperBound)
		return _iElements[nSubscript];
	else {
		std::cout << "Array bounds violation." << std::endl;
		return iErr;
	}
}


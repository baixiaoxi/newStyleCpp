#include "OperatorClz.h"

typedef void(*ptf)();
void func()
{
	std::cout << "from func" << std::endl;
}

struct S
{
	operator ptf()
	{
		return func;
	}
};

bool OperatorClz::OperatorClz::test()
{
	S s;
	s();//operates as s.operator ptf()()

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


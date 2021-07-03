#pragma once

#include "Fact.h"

namespace OperatorClz {
	class OperatorClz final : public Fact
	{
	public:
		std::string name() override { return "OperatorClz"; }
		bool test() override;
	};

	class IntVector {
	public:
		IntVector(int cElements);
		~IntVector() { delete[] _iElements; }
		int& operator[](int nSubscript);
	private:
		int* _iElements;
		int _iUpperBound;
	};
}

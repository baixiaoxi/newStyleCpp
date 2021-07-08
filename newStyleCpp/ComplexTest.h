#pragma once

#include "Fact.h"

namespace ComplexTest
{
	class ComplexTest : public Fact
	{
	public:
		std::string name() override { return "ComplexTest"; }
		bool test() override;
	};
}
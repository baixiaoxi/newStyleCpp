#pragma once

#include "Fact.h"

namespace NumericTest
{
	class NumericTest : public Fact
	{
	public:
		std::string name() override { return "NumericTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace ArrayTest
{
	class ArrayTest : public Fact
	{
	public:
		std::string name() override { return "ArrayTest"; }
		bool test() override;
	};
}
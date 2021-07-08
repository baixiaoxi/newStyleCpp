#pragma once

#include "Fact.h"

namespace ExecutionTest
{
	class ExecutionTest : public Fact
	{
	public:
		std::string name() override { return "ExecutionTest"; }
		bool test() override;
	};
}
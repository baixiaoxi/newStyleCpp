#pragma once

#include "Fact.h"

namespace ConditionVariableTest
{
	class ConditionVariableTest : public Fact
	{
	public:
		std::string name() override { return "ConditionVariableTest"; }
		bool test() override;
	};
}
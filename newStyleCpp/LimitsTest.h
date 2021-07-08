#pragma once

#include "Fact.h"

namespace LimitsTest
{
	class LimitsTest : public Fact
	{
	public:
		std::string name() override { return "LimitsTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace ClimitsTest
{
	class ClimitsTest : public Fact
	{
	public:
		std::string name() override { return "ClimitsTest"; }
		bool test() override;
	};
}
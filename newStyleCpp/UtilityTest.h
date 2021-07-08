#pragma once

#include "Fact.h"

namespace UtilityTest
{
	class UtilityTest : public Fact
	{
	public:
		std::string name() override { return "UtilityTest"; }
		bool test() override;
	};
}

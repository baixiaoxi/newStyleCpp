#pragma once

#include "Fact.h"

namespace CfenvTest
{
	class CfenvTest : public Fact
	{
	public:
		std::string name() override { return "CfenvTest"; }
		bool test() override;
	};
}
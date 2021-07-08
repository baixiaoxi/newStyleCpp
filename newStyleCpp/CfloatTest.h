#pragma once

#include "Fact.h"

namespace CfloatTest
{
	class CfloatTest : public Fact
	{
	public:
		std::string name() override { return "CfloatTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace CmathTest
{
	class CmathTest : public Fact
	{
	public:
		std::string name() override { return "CmathTest"; }
		bool test() override;
	};
}
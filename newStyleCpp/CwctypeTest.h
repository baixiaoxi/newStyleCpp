#pragma once

#include "Fact.h"

namespace CwctypeTest
{
	class CwctypeTest : public Fact
	{
	public:
		std::string name() override { return "CwctypeTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace StrstringTest
{
	class StrstringTest : public Fact
	{
	public:
		std::string name() override { return "StrstringTest"; }
		bool test() override;
	};
}
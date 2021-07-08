#pragma once

#include "Fact.h"

namespace AllocatorsTest
{
	class AllocatorsTest : public Fact
	{
	public:
		std::string name() override { return "AllocatorsTest"; }
		bool test() override;
	};
}
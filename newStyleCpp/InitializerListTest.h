#pragma once

#include "Fact.h"

namespace InitializerListTest
{
	class InitializerListTest : public Fact
	{
	public:
		std::string name() override { return "InitializerListTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace RandomTest
{
	class RandomTest : public Fact
	{
	public:
		std::string name() override { return "RandomTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace OptionalTest
{
	class OptionalTest : public Fact
	{
	public:
		std::string name() override { return "OptionalTest"; }
		bool test() override;
	};
}
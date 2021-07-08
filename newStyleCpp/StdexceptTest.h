#pragma once

#include "Fact.h"

namespace StdexceptTest
{
	class StdexceptTest : public Fact
	{
	public:
		std::string name() override { return "StdexceptTest"; }
		bool test() override;
	};
}
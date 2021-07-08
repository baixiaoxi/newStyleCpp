#pragma once

#include "Fact.h"

namespace RegexTest
{
	class RegexTest : public Fact
	{
	public:
		std::string name() override { return "RegexTest"; }
		bool test() override;
	};
}
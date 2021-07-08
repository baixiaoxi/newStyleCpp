#pragma once

#include "Fact.h"

namespace ChronoTest
{
	class ChronoTest : public Fact
	{
	public:
		std::string name() override { return "ChronoTest"; }
		bool test() override;
	};
}
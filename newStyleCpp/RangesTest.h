#pragma once

#include "Fact.h"

namespace RangesTest
{
	class RangesTest : public Fact
	{
	public:
		std::string name() override { return "RangesTest"; }
		bool test() override;
	};
}
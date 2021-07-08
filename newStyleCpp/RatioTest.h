#pragma once

#include "Fact.h"

namespace RatioTest
{
	class RatioTest : public Fact
	{
	public:
		std::string name() override { return "RatioTest"; }
		bool test() override;
	};
}
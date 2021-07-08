#pragma once

#include "Fact.h"

namespace CharconvTest
{
	class CharconvTest : public Fact
	{
	public:
		std::string name() override { return "CharconvTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace SetTest
{
	class SetTest : public Fact
	{
	public:
		std::string name() override { return "SetTest"; }
		bool test() override;
	};
}
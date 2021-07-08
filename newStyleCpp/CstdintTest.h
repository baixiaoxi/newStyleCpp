#pragma once

#include "Fact.h"

namespace CstdintTest
{
	class CstdintTest : public Fact
	{
	public:
		std::string name() override { return "CstdintTest"; }
		bool test() override;
	};
}
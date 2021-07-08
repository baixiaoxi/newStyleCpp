#pragma once

#include "Fact.h"

namespace CstddefTest
{
	class CstddefTest : public Fact
	{
	public:
		std::string name() override { return "CstddefTest"; }
		bool test() override;
	};
}
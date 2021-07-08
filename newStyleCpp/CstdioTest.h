#pragma once

#include "Fact.h"

namespace CstdioTest
{
	class CstdioTest : public Fact
	{
	public:
		std::string name() override { return "CstdioTest"; }
		bool test() override;
	};
}
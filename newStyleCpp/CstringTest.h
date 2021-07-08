#pragma once

#include "Fact.h"

namespace CstringTest
{
	class CstringTest : public Fact
	{
	public:
		std::string name() override { return "CstringTest"; }
		bool test() override;
	};
}
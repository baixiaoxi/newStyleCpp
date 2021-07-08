#pragma once

#include "Fact.h"

namespace CstdargTest
{
	class CstdargTest : public Fact
	{
	public:
		std::string name() override { return "CstdargTest"; }
		bool test() override;
	};
}
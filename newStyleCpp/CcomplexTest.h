#pragma once

#include "Fact.h"

namespace CcomplexTest
{
	class CcomplexTest : public Fact
	{
	public:
		std::string name() override { return "CcomplexTest"; }
		bool test() override;
	};
}
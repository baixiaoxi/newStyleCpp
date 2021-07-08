#pragma once

#include "Fact.h"

namespace ClocaleTest
{
	class ClocaleTest : public Fact
	{
	public:
		std::string name() override { return "ClocaleTest"; }
		bool test() override;
	};
}
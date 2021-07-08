#pragma once

#include "Fact.h"

namespace CctypeTest
{
	class CctypeTest : public Fact
	{
	public:
		std::string name() override { return "CctypeTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace CinttypesTest
{
	class CinttypesTest : public Fact
	{
	public:
		std::string name() override { return "CinttypesTest"; }
		bool test() override;
	};
}
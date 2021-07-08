#pragma once

#include "Fact.h"

namespace CsetjmpTest
{
	class CsetjmpTest : public Fact
	{
	public:
		std::string name() override { return "CsetjmpTest"; }
		bool test() override;
	};
}
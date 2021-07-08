#pragma once

#include "Fact.h"

namespace CtagmathTest
{
	class CtagmathTest : public Fact
	{
	public:
		std::string name() override { return "CtagmathTest"; }
		bool test() override;
	};
}
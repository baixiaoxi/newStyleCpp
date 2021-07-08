#pragma once

#include "Fact.h"

namespace FunctionalTest
{
	class FunctionalTest : public Fact
	{
	public:
		std::string name() override { return "FunctionalTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace StrstreamTest
{
	class StrstreamTest : public Fact
	{
	public:
		std::string name() override { return "StrstreamTest"; }
		bool test() override;
	};
}
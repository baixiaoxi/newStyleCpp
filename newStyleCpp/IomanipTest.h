#pragma once

#include "Fact.h"

namespace IomanipTest
{
	class IomanipTest : public Fact
	{
	public:
		std::string name() override { return "IomanipTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace IosTest
{
	class IosTest : public Fact
	{
	public:
		std::string name() override { return "IosTest"; }
		bool test() override;
	};
}
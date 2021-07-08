#pragma once

#include "Fact.h"

namespace AnyTest
{
	class AnyTest : public Fact
	{
	public:
		std::string name() override { return "AnyTest"; }
		bool test() override;
	};
}
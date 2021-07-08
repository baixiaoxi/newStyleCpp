#pragma once

#include "Fact.h"

namespace NewTest
{
	class NewTest : public Fact
	{
	public:
		std::string name() override { return "NewTest"; }
		bool test() override;
	};
}
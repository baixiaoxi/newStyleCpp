#pragma once

#include "Fact.h"

namespace FutureTest
{
	class FutureTest : public Fact
	{
	public:
		std::string name() override { return "FutureTest"; }
		bool test() override;
	};
}
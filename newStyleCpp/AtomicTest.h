#pragma once

#include "Fact.h"

namespace AtomicTest
{
	class AtomicTest : public Fact
	{
	public:
		std::string name() override { return "AtomicTest"; }
		bool test() override;
	};
}
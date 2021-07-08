#pragma once

#include "Fact.h"

namespace MemoryTest
{
	class MemoryTest : public Fact
	{
	public:
		std::string name() override { return "MemoryTest"; }
		bool test() override;
	};
}
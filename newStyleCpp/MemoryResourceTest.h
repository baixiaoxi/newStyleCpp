#pragma once

#include "Fact.h"

namespace MemoryResourceTest
{
	class MemoryResourceTest : public Fact
	{
	public:
		std::string name() override { return "MemoryResourceTest"; }
		bool test() override;
	};
}
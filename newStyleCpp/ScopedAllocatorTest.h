#pragma once

#include "Fact.h"

namespace ScopedAllocatorTest
{
	class ScopedAllocatorTest : public Fact
	{
	public:
		std::string name() override { return "ScopedAllocatorTest"; }
		bool test() override;
	};
}
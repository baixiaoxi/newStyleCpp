#pragma once
#include "Fact.h"

namespace UnorderedMapTest
{
	class UnorderedMapTest : public Fact
	{
	public:
		std::string name() override { return "UnorderedMapTest"; }
		bool test() override;
	};
}

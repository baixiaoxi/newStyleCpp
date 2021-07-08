#pragma once
#include "Fact.h"

namespace UnorderedSetTest
{
	class UnorderedSetTest : public Fact
	{
	public:
		std::string name() override { return "UnorderedSetTest"; }
		bool test() override;
	};
}

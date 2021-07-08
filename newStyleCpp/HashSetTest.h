#pragma once

#include "Fact.h"

namespace HashSetTest
{
	class HashSetTest : public Fact
	{
	public:
		std::string name() override { return "HashSetTest"; }
		bool test() override;
	};
}
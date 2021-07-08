#pragma once

#include "Fact.h"

namespace HashMapTest
{
	class HashMapTest : public Fact
	{
	public:
		std::string name() override { return "HashMapTest"; }
		bool test() override;
	};
}
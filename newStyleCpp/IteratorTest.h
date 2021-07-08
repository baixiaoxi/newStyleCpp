#pragma once

#include "Fact.h"

namespace IteratorTest
{
	class IteratorTest : public Fact
	{
	public:
		std::string name() override { return "IteratorTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace TypeIndexTest
{
	class TypeIndexTest : public Fact
	{
	public:
		std::string name() override { return "TypeIndexTest"; }
		bool test() override;
	};
}
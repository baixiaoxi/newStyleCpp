#pragma once
#include "Fact.h"

namespace TypeTraitsTest
{
	class TypeTraitsTest : public Fact
	{
	public:
		std::string name() override { return "TypeTraitsTest"; }
		bool test() override;
	};
}

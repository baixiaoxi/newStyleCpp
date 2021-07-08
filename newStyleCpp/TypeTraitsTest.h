#pragma once
#include "Fact.h"
#include <type_traits>

namespace TypeTraitsTest
{
	class TypeTraitsTest : public Fact
	{
	public:
		std::string name() override { return "TypeTraitsTest"; }
		bool test() override;
	};
}

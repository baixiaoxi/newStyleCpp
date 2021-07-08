#pragma once

#include "Fact.h"

namespace TypeinfoTest
{
	class TypeinfoTest : public Fact
	{
	public:
		std::string name() override { return "TypeinfoTest"; }
		bool test() override;
	};
}
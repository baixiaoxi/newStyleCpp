#pragma once

#include "Fact.h"

namespace VectorTest
{
	class VectorTest : public Fact
	{
	public:
		std::string name() override { return "VectorTest"; }
		bool test() override;
	};
}

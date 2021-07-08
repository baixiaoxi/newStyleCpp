#pragma once

#include "Fact.h"

namespace TupleTest
{
	class TupleTest : public Fact
	{
	public:
		std::string name() override { return "TupleTest"; }
		bool test() override;
	};
}
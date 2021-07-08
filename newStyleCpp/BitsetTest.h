#pragma once

#include "Fact.h"

namespace BitsetTest
{
	class BitsetTest : public Fact
	{
	public:
		std::string name() override { return "BitsetTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace BitTest
{
	class BitTest : public Fact
	{
	public:
		std::string name() override { return "BitTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace AlgorithmTest
{
	class AlgorithmTest : public Fact
	{
	public:
		std::string name() override { return "AlgorithmTest"; }
		bool test() override;
	};
}
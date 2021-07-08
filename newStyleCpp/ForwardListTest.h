#pragma once

#include "Fact.h"

namespace ForwardListTest
{
	class ForwardListTest : public Fact
	{
	public:
		std::string name() override { return "ForwardListTest"; }
		bool test() override;
	};
}
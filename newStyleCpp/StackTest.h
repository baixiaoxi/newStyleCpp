#pragma once

#include "Fact.h"

namespace StackTest
{
	class StackTest : public Fact
	{
	public:
		std::string name() override { return "StackTest"; }
		bool test() override;
	};
}
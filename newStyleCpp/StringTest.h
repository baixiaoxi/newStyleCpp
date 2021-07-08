#pragma once

#include "Fact.h"

namespace StringTest
{
	class StringTest : public Fact
	{
	public:
		std::string name() override { return "StringTest"; }
		bool test() override;
	};
}
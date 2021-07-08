#pragma once

#include "Fact.h"

namespace StringViewTest
{
	class StringViewTest : public Fact
	{
	public:
		std::string name() override { return "StringViewTest"; }
		bool test() override;
	};
}
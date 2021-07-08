#pragma once

#include "Fact.h"

namespace ListTest
{
	class ListTest : public Fact
	{
	public:
		std::string name() override { return "ListTest"; }
		bool test() override;
	};
}
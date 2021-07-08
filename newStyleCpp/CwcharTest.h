#pragma once

#include "Fact.h"

namespace CwcharTest
{
	class CwcharTest : public Fact
	{
	public:
		std::string name() override { return "CwcharTest"; }
		bool test() override;
	};
}
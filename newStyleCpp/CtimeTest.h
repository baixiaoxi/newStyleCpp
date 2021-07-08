#pragma once

#include "Fact.h"

namespace CtimeTest
{
	class CtimeTest : public Fact
	{
	public:
		std::string name() override { return "CtimeTest"; }
		bool test() override;
	};
}
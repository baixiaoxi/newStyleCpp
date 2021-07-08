#pragma once

#include "Fact.h"

namespace CerrnoTest
{
	class CerrnoTest : public Fact
	{
	public:
		std::string name() override { return "CerrnoTest"; }
		bool test() override;
	};
}
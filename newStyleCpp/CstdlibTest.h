#pragma once

#include "Fact.h"

namespace CstdlibTest
{
	class CstdlibTest : public Fact
	{
	public:
		std::string name() override { return "CstdlibTest"; }
		bool test() override;
	};
}
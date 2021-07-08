#pragma once

#include "Fact.h"

namespace CstdboolTest
{
	class CstdboolTest : public Fact
	{
	public:
		std::string name() override { return "CstdboolTest"; }
		bool test() override;
	};
}
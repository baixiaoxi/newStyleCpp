#pragma once

#include "Fact.h"

namespace CstdalignTest
{
	class CstdalignTest : public Fact
	{
	public:
		std::string name() override { return "CstdalignTest"; }
		bool test() override;
	};
}
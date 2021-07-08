#pragma once

#include "Fact.h"

namespace MutexTest
{
	class MutexTest : public Fact
	{
	public:
		std::string name() override { return "MutexTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace SharedMutexTest
{
	class SharedMutexTest : public Fact
	{
	public:
		std::string name() override { return "SharedMutexTest"; }
		bool test() override;
	};
}
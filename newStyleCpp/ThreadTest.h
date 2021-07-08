#pragma once

#include "Fact.h"

namespace ThreadTest
{
	class ThreadTest : public Fact
	{
	public:
		std::string name() override { return "ThreadTest"; }
		bool test() override;
	};
}
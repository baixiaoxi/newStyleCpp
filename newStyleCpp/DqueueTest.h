#pragma once

#include "Fact.h"

namespace DqueueTest
{
	class DqueueTest : public Fact
	{
	public:
		std::string name() override { return "DqueueTest"; }
		bool test() override;
	};
}
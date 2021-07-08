#pragma once

#include "Fact.h"

namespace QueueTest
{
	class QueueTest : public Fact
	{
	public:
		std::string name() override { return "QueueTest"; }
		bool test() override;
	};
}
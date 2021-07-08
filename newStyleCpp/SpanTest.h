#pragma once

#include "Fact.h"

namespace SpanTest
{
	class SpanTest : public Fact
	{
	public:
		std::string name() override { return "SpanTest"; }
		bool test() override;
	};
}
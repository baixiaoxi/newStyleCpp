#pragma once

#include "Fact.h"

namespace OstreamTest
{
	class OstreamTest : public Fact
	{
	public:
		std::string name() override { return "OstreamTest"; }
		bool test() override;
	};
}
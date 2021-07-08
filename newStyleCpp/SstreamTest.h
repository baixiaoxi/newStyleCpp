#pragma once

#include "Fact.h"

namespace SstreamTest
{
	class SstreamTest : public Fact
	{
	public:
		std::string name() override { return "SstreamTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace FstreamTest
{
	class FstreamTest : public Fact
	{
	public:
		std::string name() override { return "FstreamTest"; }
		bool test() override;
	};
}
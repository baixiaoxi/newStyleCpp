#pragma once

#include "Fact.h"

namespace IstreamTest
{
	class IstreamTest : public Fact
	{
	public:
		std::string name() override { return "IstreamTest"; }
		bool test() override;
	};
}
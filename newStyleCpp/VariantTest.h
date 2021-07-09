#pragma once

#include "Fact.h"

namespace VariantTest
{
	class VariantTest : public Fact
	{
	public:
		std::string name() override { return "VariantTest"; }
		bool test() override;
	};
}

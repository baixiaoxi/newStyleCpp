#pragma once

#include "Fact.h"

namespace MapTest
{
	class MapTest : public Fact
	{
	public:
		std::string name() override { return "MapTest"; }
		bool test() override;
	};
}
#pragma once

#include "Fact.h"

namespace CucharTest
{
	class CucharTest : public Fact
	{
	public:
		std::string name() override { return "CucharTest"; }
		bool test() override;
	};
}
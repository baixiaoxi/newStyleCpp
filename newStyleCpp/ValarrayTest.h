#pragma once

#include "Fact.h"

namespace ValarrayTest
{
	class ValarrayTest : public Fact
	{
	public:
		std::string name() override { return "ValarrayTest"; }
		bool test() override;
	};
}

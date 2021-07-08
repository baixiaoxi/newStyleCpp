#pragma once

#include "Fact.h"

namespace IostreamTest
{
	class IostreamTest : public Fact
	{
	public:
		std::string name() override { return "IostreamTest"; }
		bool test() override;
	};
}
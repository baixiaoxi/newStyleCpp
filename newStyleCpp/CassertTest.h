#pragma once

#include "Fact.h"

namespace CassertTest
{
	class CassertTest : public Fact
	{
	public:
		std::string name() override { return "CassertTest"; }
		bool test() override;
	};
}
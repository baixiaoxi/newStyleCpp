#pragma once

#include "Fact.h"

namespace Ciso646Test
{
	class Ciso646Test : public Fact
	{
	public:
		std::string name() override { return "Ciso646Test"; }
		bool test() override;
	};
}
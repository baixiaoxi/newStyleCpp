#pragma once

#include "Fact.h"

namespace Move
{
	class Move : public Fact
	{
	public:
		std::string name() override { return "Move"; }
		bool test() override;
	};

	class MemoryBlock
	{

	};
}

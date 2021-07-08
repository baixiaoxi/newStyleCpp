#pragma once

#include "Fact.h"

namespace IosfwdTest
{
	class IosfwdTest : public Fact
	{
	public:
		std::string name() override { return "IosfwdTest"; }
		bool test() override;
	};
}
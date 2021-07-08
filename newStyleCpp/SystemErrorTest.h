#pragma once

#include "Fact.h"

namespace SystemErrorTest
{
	class SystemErrorTest : public Fact
	{
	public:
		std::string name() override { return "SystemErrorTest"; }
		bool test() override;
	};
}
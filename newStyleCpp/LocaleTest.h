#pragma once

#include "Fact.h"

namespace LocaleTest
{
	class LocaleTest : public Fact
	{
	public:
		std::string name() override { return "LocaleTest"; }
		bool test() override;
	};
}
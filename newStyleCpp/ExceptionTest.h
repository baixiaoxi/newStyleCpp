#pragma once

#include "Fact.h"

namespace ExceptionTest
{
	class ExceptionTest : public Fact
	{
	public:
		std::string name() override { return "ExceptionTest"; }
		bool test() override;
	};
}
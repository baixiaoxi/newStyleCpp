#pragma once

#include "Fact.h"

namespace CsignalTest
{
	class CsignalTest : public Fact
	{
	public:
		std::string name() override { return "CsignalTest"; }
		bool test() override;
	};
}
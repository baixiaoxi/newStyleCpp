#pragma once

#include "Fact.h"

namespace CvtWstringTest
{
	class CvtWstringTest : public Fact
	{
	public:
		std::string name() override { return "CvtWstringTest"; }
		bool test() override;
	};
}
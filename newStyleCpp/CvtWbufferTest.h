#pragma once

#include "Fact.h"

namespace CvtWbufferTest
{
	class CvtWbufferTest : public Fact
	{
	public:
		std::string name() override { return "CvtWbufferTest"; }
		bool test() override;
	};
}
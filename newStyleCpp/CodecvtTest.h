#pragma once

#include "Fact.h"

namespace CodecvtTest
{
	class CodecvtTest : public Fact
	{
	public:
		std::string name() override { return "CodecvtTest"; }
		bool test() override;
	};
}
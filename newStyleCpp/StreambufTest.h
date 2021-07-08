#pragma once

#include "Fact.h"

namespace StreambufTest
{
	class StreambufTest : public Fact
	{
	public:
		std::string name() override { return "StreambufTest"; }
		bool test() override;
	};
}
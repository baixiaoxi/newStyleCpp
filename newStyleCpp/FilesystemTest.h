#pragma once

#include "Fact.h"

namespace FilesystemTest
{
	class FilesystemTest : public Fact
	{
	public:
		std::string name() override { return "FilesystemTest"; }
		bool test() override;
	};
}
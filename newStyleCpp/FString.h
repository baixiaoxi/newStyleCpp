#pragma once

#include "Fact.h"

class FString final : public Fact {
public:
	bool test() override;
	std::string name() override { return "FString"; }
};



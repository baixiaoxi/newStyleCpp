#pragma once

#include "Fact.h"

class Other final : public Fact {
public:
	bool test() override;
	std::string name() override { return "Other"; }
};
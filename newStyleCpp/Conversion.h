#pragma once

#include "Fact.h"

class Conversion final : public Fact {
public:
	bool test() override;
	std::string name() override { return "Conversion"; }
};

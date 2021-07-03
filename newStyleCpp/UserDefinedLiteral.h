#pragma once

#include "Fact.h"

class UserDefinedLiteral final : public Fact {
public:
	bool test() override;
	std::string name() override { return "UserDefinedLiteral"; }
};

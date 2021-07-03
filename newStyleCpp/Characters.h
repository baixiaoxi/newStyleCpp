#pragma once

#include "Fact.h"
#include <windows.h>

class Characters final : public Fact {
public:
	bool test() override;
	std::string name() override { return "Characters"; }
private:
};
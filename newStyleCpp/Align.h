#pragma once

#include "Fact.h"

class Align final : public Fact {
public:
	bool test() override;
	std::string name() override { return "Align"; }
};

struct alignas(16) Bar
{
	int i;
	int n;
	alignas(4) char arr[3];
	short s;
};
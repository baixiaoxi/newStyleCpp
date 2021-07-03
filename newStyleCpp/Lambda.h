#pragma once

#include "Fact.h"
#include <algorithm>
#include <cmath>

namespace Lambda
{
	class Lambda : public Fact {
	public:
		std::string name() override { return "Lambda"; }
		bool test() override;
	private:
		void abssort(float* x, unsigned n) {
			std::sort(x, x + n, [](float a, float b) {// lambda
				return (std::abs(a) < std::abs(b));
				}
			);
		}
	};
}
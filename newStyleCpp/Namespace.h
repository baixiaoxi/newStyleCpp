#pragma once

#include "Fact.h"

class NamespaceClz final : public Fact {
public:
	std::string name() override { return "NamespaceClz"; }
	bool test() override;
};

namespace NS {
	namespace {
		void Api() {
			std::cout << "hello anonomous.api" << std::endl;
		}
	}

	namespace Version1 {
		void Api();
	}

	inline namespace Version2 {
		void Api();
	}
}

void Api();

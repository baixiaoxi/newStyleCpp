#include <iostream>
#include <vector>
#include "Characters.h"
#include "UserDefinedLiteral.h"
#include "Align.h"
#include "TrivialClz.h"
#include "Conversion.h"
#include "Pointer.h"
#include "Other.h"
#include "FString.h"
#include "Declaration.h"
#include "Template.h"
#include "Namespace.h"
#include "EnumUnion.h"
#include "Function.h"
#include "OperatorClz.h"
#include "Clz.h"
#include "Lambda.h"
#include "Move.h"
#include "StructuredBinding.h"
#include "TypeTraitsTest.h"

int main(int argc, char* argv[], char* envp[]) {
	std::vector<std::unique_ptr<Fact>> vec;

	vec.push_back(std::make_unique<Characters>());
	vec.push_back(std::make_unique<UserDefinedLiteral>());
	vec.push_back(std::make_unique<Align>());
	vec.push_back(std::make_unique<TrivialClz::TrivialClz>());
	vec.push_back(std::make_unique<Conversion>());
	vec.push_back(std::make_unique<Pointer>());
	vec.push_back(std::make_unique<Other>());
	vec.push_back(std::make_unique<FString>());
	vec.push_back(std::make_unique<Declaration>());
	vec.push_back(std::make_unique<Template>());
	vec.push_back(std::make_unique<NamespaceClz>());
	vec.push_back(std::make_unique<EnumUnion::EnumUnion>());
	vec.push_back(std::make_unique<Function::Function>());
	vec.push_back(std::make_unique<OperatorClz::OperatorClz>());
	vec.push_back(std::make_unique<Clz::Clz>());
	vec.push_back(std::make_unique<Lambda::Lambda>());
	vec.push_back(std::make_unique<Move::Move>());
	vec.push_back(std::make_unique<StructuredBinding::StructuredBinding>());
	vec.push_back(std::make_unique<TypeTraitsTest::TypeTraitsTest>());

	int index = 0;
	for (auto& fact : vec) {
		std::cout << "###############################" << std::endl;
		std::cout << ++index << "." << fact->name() << std::endl;
		std::cout << "###############################" << std::endl;
		fact->test();
	}

	/*
	std::cout << "argc:" << argc << std::endl;

	std::cout << "1.commandline parameters" << std::endl;

	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << "2.environment variables list" << std::endl;
	for (int i = 0; envp[i] != nullptr; ++i) {
		std::cout << envp[i] << std::endl;
	}
	*/

	std::cout << std::endl;
	exit(EXIT_SUCCESS);
	abort();
	atexit([] {});
}
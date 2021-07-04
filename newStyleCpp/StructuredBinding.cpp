#include "StructuredBinding.h"

bool StructuredBinding::StructuredBinding::test()
{
	Person1 p1;
	Person3 p2;
	auto&& [name, age] = p1;
	name = "Fred0";
	age = 0;

	std::cout << "p1 = {" << p1.name << ", " << p1.age << "}" << std::endl;

	auto [name1, age1] = p1;
	name1 = "Fred1";
	age1 = 1;

	std::cout << "p1 = {" << p1.name << ", " << p1.age << "}" << std::endl;

	/*auto [name2, age2] = p2;
	name = "Fred2";
	age = 2;

	std::cout << "p1 = {" << p2.name << ", " << p2.age << "}" << std::endl;*/

	return true;
}
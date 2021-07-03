#include "Declaration.h"

bool Declaration::test() {

	int a = 5;
	int& b = a;
	auto& c = b;
	b = 3;
	c = 4;
	std::cout << "typeid(b)=" << typeid(b).name() << "," << b << std::endl;
	std::cout << "typeid(c)=" << typeid(c).name() << "," << c << std::endl;

	auto a0 = { 1, 2 };
	auto b0 = { 3 };
	auto c0{ 4 };
	auto d0 = { 8, 9 };

	MyAggregate1 ma1{ 2, 'D' };
	MyAggregate2 ma2;// { 2, 'F' };
	MyAggregate3 ma3;
	MyAggregate4 ma4(2);
	MyAggregate5 ma5;

	D myD;
	myD.f(1);
	myD.g('a');

	return true;
}

int Declaration::getMonth() const
{
	return 1;
}

void Declaration::setMonth(int mn)
{
}
#include "TypeIndexTest.h"
#include <typeinfo>
#include <typeindex>
#include <string>
#include <unordered_map>
#include <memory>

namespace TypeIndexTest
{
	using namespace std;

	struct A {
		virtual ~A() {}
	};

	struct B : A {};

	struct C : A {};

	bool TypeIndexTest::test()
	{
		unordered_map<type_index, string> type_names;
		type_names[type_index(typeid(int))] = "int";
		type_names[type_index(typeid(double))] = "double";
		type_names[type_index(typeid(A))] = "A";
		type_names[type_index(typeid(B))] = "B";
		type_names[type_index(typeid(C))] = "C";

		type_index intTypeIndex = type_index(typeid(int));
		const char* name = intTypeIndex.name();
		size_t hashsCode = intTypeIndex.hash_code();

		int i;
		double d;
		A a;
		unique_ptr<A> b(new B);
		unique_ptr<A> c(new C);

		cout << "i is " << type_names[type_index(typeid(i))] << '\n';
		cout << "d is " << type_names[type_index(typeid(d))] << '\n';
		cout << "a is " << type_names[type_index(typeid(a))] << '\n';
		cout << "*b is " << type_names[type_index(typeid(*b))] << '\n';
		cout << "*c is " << type_names[type_index(typeid(*c))] << '\n';

		return true;
	}
}
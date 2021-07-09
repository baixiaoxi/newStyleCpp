#pragma once
#include <iostream>
#include <typeinfo>

namespace Test
{
	using namespace std;

	class Shape {
	public:
		virtual void virtualfunc() const {}
	};

	class Circle : public Shape {
	public:
		virtual void virtualfunc() const {}
	};

	class A {
	public:
		virtual ~A();
	};

	bool test()
	{
		// bad_cast
		Shape shape_instance;
		Shape& ref_shape = shape_instance;

		try {
			Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);
		}
		catch (bad_cast b)
		{
			cout << "Caught: " << b.what();
		}

		// bad_typeid
		A* a = NULL;
		try {
			cout << typeid(*a).name() << endl;
		}
		catch (bad_typeid)
		{
			cout << "Object is NULL" << endl;
		}

		// type_info
		const type_info& typeInfo = typeid(int);
		cout << "type_info.name == " << typeInfo.name() << endl;

		return true;
	}
}
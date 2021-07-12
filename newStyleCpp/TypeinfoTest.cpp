#include "TypeinfoTest.h"
#include <typeinfo>

namespace TypeinfoTest
{
	using namespace std;

	class Shape
	{
	public:
		virtual void virtualfunc() const {}
	};

	class Circle : public Shape
	{
	public:
		virtual void virtualfunc() const {}
	};

	class A
	{
	public:
		virtual ~A();
	};

	bool TypeinfoTest::test()
	{
		// 1.bad_cast
		Shape shape_instance;
		Shape& ref_shape = shape_instance;

		try {
			Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);
		}
		catch (bad_cast b)
		{
			cout << "Caught: " << b.what();
		}

		// 2.bad_typeid
		A* a = nullptr;
		try
		{
			cout << typeid(*a).name() << endl;
		}
		catch (bad_typeid)
		{
			cout << "Object is nullptr " << endl;
		}

		// 3.type_info
		const type_info& ti = typeid(int);
		cout << "type_info.name == " << ti.name() << ", raw_name == " << ti.raw_name() << endl;

		return true;
	}
}
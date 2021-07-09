#include "TypeinfoTest.h"
//#include <typeinfo>

namespace TypeinfoTest
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

	bool TypeinfoTest::test()
	{
		Shape shape_instance;
		Shape& ref_shape = shape_instance;

		try {
			Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);
		}
		catch (bad_cast b)
		{
			cout << "Caught: " << b.what();
		}

		return true;
	}
}
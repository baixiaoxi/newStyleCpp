#include "TypeTraitsTest.h"
#include <type_traits>
#include <typeindex>
#include <typeinfo>

namespace TypeTraitsTest
{
	using namespace std;

	void is_copy_constructible_test()
	{
		struct Copyable
		{
			int val;
		};

		struct NotCopyable
		{
			NotCopyable(const NotCopyable&) = delete;

			int val;
		};
		cout << "is_copy_constructible<Copyable> == " << boolalpha << is_copy_constructible<Copyable>::value << std::endl;
		cout << "is_copy_constructible<NotCopyable> == " << boolalpha << is_copy_constructible<NotCopyable>::value << std::endl;
	}

	struct S {
		void f() {
			std::cout << "invoked non-cv-qualified S.f()" << std::endl;
		}
		void f() const {
			std::cout << "invoked const S.f()" << std::endl;
		}
		void f() volatile {
			std::cout << "invoked volatile S.f()" << std::endl;
		}
		void f() const volatile {
			std::cout << "invoked const volatile S.f()" << std::endl;
		}
	};

	template <class T>
	void invoke() {
		T t;
		((T*)&t)->f();
	}


	bool TypeTraitsTest::test()
	{
		is_copy_constructible_test();

		// 1.add_const
		add_const<int>::type* p0 = (const int*)0;
		cout << "add_const<int> == " << typeid(*p0).name() << endl;
		invoke<S>();
		invoke<add_const<S>::type>();// add_const
		invoke<add_volatile<S>::type>();// add_volatile
		invoke<add_cv<S>::type>();// add_cv
		// 2.add_lvalue_reference
		int val = 0;
		add_lvalue_reference_t<int> p1 = (int&)val;
		cout << "add_lvalue_reference_t<int> == " << typeid(p1).name() << endl;
		// 3.add_rvalue_reference
		static_assert(is_same<add_rvalue_reference<string>::type, string&&>::value, "Expected add_rvalue_reference_t<string> to be string&&");
		static_assert(is_same<add_rvalue_reference_t<string*>, string*&&>::value, "Expected add_rvalue_reference_t<string*> to be string*&&");
		// 4.reference collapsing
		static_assert(is_same<add_rvalue_reference<string&>::type, string&>::value, "Expected add_rvalue_reference_t<string&> to be string&");
		static_assert(is_same<add_rvalue_reference_t<string&&>, string&&>::value, "Expected add_rvalue_reference_t<string&&> to be string&&");
		cout << "All static_assert tests of add_rvalue_reference passed." << endl;
		// 5.add_pointer
		add_pointer_t<int>* p2 = (int**)0;
		cout << "add_pointer_t<int> == " << typeid(*p2).name() << endl;
		// 6.add_volatile
		add_volatile_t<int>* p3 = (volatile int*)0;
		cout << "add_volatile<int> == " << typeid(*p3).name() << endl;
		// 7.aligned_storage
		typedef aligned_storage<sizeof(int), alignment_of<double>::value>::type New_type;
		cout << "alignment_of<int> == " << alignment_of<int>::value << endl;
		cout << "aligned to double == " << alignment_of<New_type>::value << endl;
		// 8.aligned_union
		union U_type
		{
			int i;
			float f;
			double d;
			U_type(float e) : f(e) {}
		};
		typedef aligned_union<16, int, float, double>::type aligned_U_type;
		aligned_U_type au;
		U_type* u = new (&au) U_type(1.0f);
		if (nullptr != u)
		{
			cout << "value of u->i is " << u->i << endl;
			u->~U_type();
		}
		// 9.alignment_of
		cout << "int alignment = " << alignment_of<int>::value << endl;
		// 10.common_type
		struct Base {};
		struct Derived : Base {};
		typedef std::common_type<unsigned char, short, int>::type NumericType;
		typedef std::common_type<float, double>::type FloatType;
		typedef std::common_type<const int, volatile int>::type ModifiedIntType;
		typedef std::common_type<Base, Derived>::type ClassType;

		std::cout << std::boolalpha;
		std::cout << "Test for typedefs of common_type int" << std::endl;
		std::cout << "NumericType: " << std::is_same<int, NumericType>::value << std::endl;
		std::cout << "FloatType: " << std::is_same<int, FloatType>::value << std::endl;
		std::cout << "ModifiedIntType: " << std::is_same<int, ModifiedIntType>::value << std::endl;
		std::cout << "ClassType: " << std::is_same<int, ClassType>::value << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << "Test for typedefs of common_type double" << std::endl;
		std::cout << "NumericType: " << std::is_same<double, NumericType>::value << std::endl;
		std::cout << "FloatType: " << std::is_same<double, FloatType>::value << std::endl;
		std::cout << "ModifiedIntType: " << std::is_same<double, ModifiedIntType>::value << std::endl;
		std::cout << "ClassType: " << std::is_same<double, ClassType>::value << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << "Test for typedefs of common_type Base" << std::endl;
		std::cout << "NumericType: " << std::is_same<Base, NumericType>::value << std::endl;
		std::cout << "FloatType: " << std::is_same<Base, FloatType>::value << std::endl;
		std::cout << "ModifiedIntType: " << std::is_same<Base, ModifiedIntType>::value << std::endl;
		std::cout << "ClassType: " << std::is_same<Base, ClassType>::value << std::endl;
		// 11.conditional
		typedef conditional<is_pod<Base>::value, int, double>::type selectType;
		// 12.decay class
		// 13.enable_if
		// 14.

		return true;
	}
}
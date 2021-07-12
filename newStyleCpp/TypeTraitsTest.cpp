#include "TypeTraitsTest.h"
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <utility>
#include <tuple>
#include <stddef.h>
#include <array>
#include <string>

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
	// enable_if
	namespace detail
	{
		void* voidify(const volatile void* ptr) noexcept { return const_cast<void*>(ptr); }
	}

	// #1, enabled via the return type
	template<class T>
	typename enable_if<is_trivially_default_constructible<T>::value>::type construct(T*)
	{
		cout << "default constructing trivially default constructible T\n";
	}
	template<class T>
	typename enable_if<!is_trivially_constructible<T>::value>::type construct(T* p)
	{
		cout << "default constructing non-trivially default constructible T\n";
		::new(detail::voidify(p))T;
	}
	// #2
	template<class T, class... Args>
	enable_if_t<is_constructible<T, Args&&...>::value> construct(T* p, Args&&... args)
	{
		cout << "constructing T with operation\n";
		::new(detail::voidify(p)) T(static_cast<Args&&>(args)...);
	}
	// #3, enabled via a parameter
	template<class T>
	void destroy(T*, typename enable_if<is_trivially_destructible<T>::value>::type* = 0)
	{
		cout << "destroying trivially destructible T\n";
	}
	// #4, enabled via a non-type template parameter
	template<class T, typename enable_if < !is_trivially_destructible<T>{} && (is_class<T>{} || is_union<T>{}), bool > ::type = true >
	void destroy(T * t)
	{
		cout << "destroying non-trivially destructible T\n";
		t->~T();
	}
	template<class T>
	void baixiaoxiTest(typename enable_if<is_trivial_v<T>, T>::type)
	{
	}
	// #5, enabled via a type template parameter
	template<class T, typename = enable_if_t<is_array<T>::value>>
	void destroy(T* t)
	{
		for (size_t i = 0; i < extent<T>::value; ++i)
		{
			destroy((*t)[i]);
		}
	}

	template<class T, class Enable = void>
	class A { };

	template<class T>
	class A<T, typename enable_if<is_floating_point<T>::value>::type> {	};
	// index_sequence
	template<typename Array, size_t... I>
	auto a2t_(const Array& a, index_sequence<I...>)
	{
		return make_tuple(a[I]...);
	}

	template<typename T, size_t N>
	auto a2t(const array<T, N>& a)
	{
		return a2t_(a, make_index_sequence<N>());
	}

	struct S2 {
		double operator()(char, int&);
		float operator()(int) { return 1.0; }
	};
	struct abstract
	{
		virtual int val() = 0;
	};
	struct functional
	{
		int f();
	};
	auto test1(int) noexcept -> int(*)()
	{
		return nullptr;
	}
	auto test2(int) -> int(*)()
	{
		return nullptr;
	}
	enum class S3 : short
	{
		SSS1 = 0,
	};

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
		typedef conditional<is_standard_layout<Base>::value, int, double>::type selectType;
		// 12.decay class
		decay<int*>::type inVal = nullptr;// remove const/volatile/reference
		// 13.enable_if
		int ei = 13;
		construct<int>(&ei);
		S es;
		baixiaoxiTest<S>(es);
		// 14.extent
		cout << extent<int[5][10], 1>::value << endl;
		// 15.integer_sequence
		make_index_sequence<5> indexSe = make_index_sequence<5>();// index [0, 5)
		index_sequence<0, 5, 3> aa = index_sequence<0, 5, 3>();// index (0, 5, 3)
		auto seSize = indexSe.size();
		// 16.integral_constant
		int icv = integral_constant<int, 5>::value;
		bool icv2 = integral_constant<bool, false>::value;
		// 17.invoke_result
		invoke_result<S2, char, int&>::type b = 3.14;
		static_assert(is_same<decltype(b), double>::value, "");
		// 18.is_abstract
		cout << boolalpha << is_abstract<abstract>::value << endl;
		// 19.is_arithmetic
		cout << boolalpha << is_arithmetic<float>::value << endl;
		// 20.is_array
		cout << boolalpha << is_array<int[5][3]>::value << endl;
		// 21.is_assignable
		cout << boolalpha << is_assignable<S, S2>::value << endl;
		// 22.is_base_of
		cout << boolalpha << is_base_of<S, S2>::value << endl;
		// 23.is_class
		cout << boolalpha << is_class<S>::value << endl;
		// 24.is_compound
		cout << boolalpha << is_compound<S>::value << endl;
		// 25.is_const
		cout << boolalpha << is_const<const int>::value << endl;
		// 26.is_constructible
		cout << boolalpha << is_constructible<S, int, string>::value << endl;
		// 27.is_convertible
		cout << boolalpha << is_convertible<S, S2>::value << endl;
		// 28.is_copy_assignable
		cout << boolalpha << is_copy_assignable<S>::value << endl;
		// 29.is_copy_constructible
		cout << boolalpha << is_copy_constructible<S>::value << endl;
		// 30.is_default_constructible
		cout << boolalpha << is_default_constructible<S>::value << endl;
		// 31.is_destructible
		cout << boolalpha << is_destructible<S>::value << endl;
		// 32.is_empty
		cout << boolalpha << is_empty<S>::value << endl;
		// 33.is_enum
		cout << boolalpha << is_enum<S>::value << endl;
		// 34.is_final
		cout << boolalpha << is_final<S>::value << endl;
		// 35.is_floating_point
		cout << boolalpha << is_floating_point<float>::value << endl;
		// 36.is_function
		cout << boolalpha << is_function<functional>::value << endl;
		// 37.is_fundamental
		cout << boolalpha << is_fundamental<const int>::value << endl;
		// 38.is_integral
		cout << boolalpha << is_integral<const int>::value << endl;
		// 39.is_invocable
		cout << boolalpha << is_invocable<decltype(test1), short>::value << endl;
		cout << boolalpha << is_invocable_r<int(*)(), decltype(test1), int>::value << endl;
		cout << boolalpha << is_invocable_r<long(*)(), decltype(test1), int>::value << endl;
		cout << boolalpha << is_nothrow_invocable<decltype(test1), int>::value << endl;
		cout << boolalpha << is_nothrow_invocable<decltype(test2), int>::value << endl;
		cout << boolalpha << is_nothrow_invocable_r<int(*)(), decltype(test1), int>::value << endl;
		cout << boolalpha << is_nothrow_invocable_r<int(*)(), decltype(test2), int>::value << endl;
		// 40.is_literal_type
		// cout << boolalpha << is_literal_type<S>::value << endl;
		// 41.is_lvalue_reference
		cout << boolalpha << is_lvalue_reference<const int>::value << endl;
		// 42.is_member_function_pointer
		cout << boolalpha << is_member_function_pointer<int (functional::*)()>::value << endl;
		// 43.is_member_object_pointer
		cout << boolalpha << is_member_object_pointer<int functional::*>::value << endl;
		// 44.is_member_pointer
		cout << boolalpha << is_member_object_pointer<int functional::*>::value << endl;
		cout << boolalpha << is_member_function_pointer<int (functional::*)()>::value << endl;
		// 45.is_move_assignable
		cout << boolalpha << is_move_assignable<S>::value << endl;
		// 46.is_move_constructible
		cout << boolalpha << is_move_constructible<S>::value << endl;
		// 47.is_nothrow_assignable
		cout << boolalpha << is_nothrow_assignable<S, S2>::value << endl;
		// 48.is_nothrow_constructible
		cout << boolalpha << is_nothrow_constructible<S>::value << endl;
		// 49.is_nothrow_copy_assignable
		cout << boolalpha << is_nothrow_copy_assignable<S>::value << endl;
		// 50.is_nothrow_copy_constructible
		cout << boolalpha << is_nothrow_copy_constructible<S>::value << endl;
		// 51.is_nothrow_default_constructible
		cout << boolalpha << is_nothrow_default_constructible<S>::value << endl;
		// 52.is_nothrow_destructible
		cout << boolalpha << is_nothrow_destructible<S>::value << endl;
		// 53.is_nothrow_move_assignable
		cout << boolalpha << is_nothrow_move_assignable<S>::value << endl;
		// 54.is_nothrow_move_constructible
		cout << boolalpha << is_nothrow_move_constructible<S>::value << endl;
		// 55.is_null_pointer
		cout << boolalpha << is_null_pointer<S*>::value << endl;
		// 56.is_object
		cout << boolalpha << is_object<const int>::value << endl;
		// 57.is_pod
		// cout << boolalpha << is_pod<S>::value << endl;
		// 58.is_pointer
		cout << boolalpha << is_pointer<const int*>::value << endl;
		// 59.is_polymorphic
		cout << boolalpha << is_polymorphic<S>::value << endl;
		// 60.is_reference
		cout << boolalpha << is_reference<const int&>::value << endl;
		// 61.is_rvalue_reference
		cout << boolalpha << is_rvalue_reference<const int&>::value << endl;
		// 62.is_same
		cout << boolalpha << is_same<const int, S>::value << endl;
		// 63.is_scalar
		cout << boolalpha << is_scalar<const int>::value << endl;
		// 64.is_signed
		cout << boolalpha << is_signed<const int>::value << endl;
		// 65.is_standard_layout
		cout << boolalpha << is_standard_layout<const int>::value << endl;
		// 66.is_trivial
		cout << boolalpha << is_trivial<S>::value << endl;
		// 67.is_trivially_assignable
		cout << boolalpha << is_trivially_assignable<S, S2>::value << endl;
		// 68.is_trivially_constructible
		cout << boolalpha << is_trivially_constructible<S>::value << endl;
		// 69.is_trivially_copy_assignable
		cout << boolalpha << is_trivially_copy_assignable<S>::value << endl;
		// 70.is_trivially_copy_constructible
		cout << boolalpha << is_trivially_copy_constructible<S>::value << endl;
		// 71.is_trivially_copyable
		cout << boolalpha << is_trivially_copyable<S>::value << endl;
		// 72.is_trivially_default_constructible
		cout << boolalpha << is_trivially_default_constructible<S>::value << endl;
		// 73.is_trivially_destructible
		cout << boolalpha << is_trivially_destructible<S>::value << endl;
		// 74.is_trivially_move_assignable
		cout << boolalpha << is_trivially_move_assignable<S>::value << endl;
		// 75.is_trivially_move_constructible
		cout << boolalpha << is_trivially_move_constructible<S>::value << endl;
		// 76.is_union
		cout << boolalpha << is_union<S>::value << endl;
		// 77.is_unsigned
		cout << boolalpha << is_unsigned<const int>::value << endl;
		// 78.is_void
		cout << boolalpha << is_void<const int>::value << endl;
		// 79.is_volatile
		cout << boolalpha << is_volatile<const int>::value << endl;
		// 80.make_signed
		make_signed<const int>::type ms = 3;
		// 81.make_unsigned
		make_unsigned<const int>::type mus = 3;
		// 82.rank
		cout << boolalpha << rank<int[5][10]>::value << endl;// number of dimensions of the array type
		// 83.remove_all_extents
		cout << "name: " << typeid(remove_all_extents<int[5][10]>::type).name() << endl;
		// 84.remove_const
		cout << boolalpha << typeid(remove_const<const int>::type).name() << " == int" << endl;
		// 85.remove_cv
		cout << boolalpha << typeid(remove_cv<const int>::type).name() << endl;
		// 86.remove_extent
		cout << boolalpha << typeid(remove_extent<int[5][10]>::type).name() << " == int[5]" << endl;
		// 87.remove_pointer
		cout << boolalpha << typeid(remove_pointer<const int*>::type).name() << " == const int*" << endl;
		// 88.remove_reference
		cout << boolalpha << typeid(remove_reference<const int&>::type).name() << " == const int" << endl;
		// 89.remove_volatile
		cout << boolalpha << typeid(remove_volatile<volatile int>::type).name() << " == int" << endl;
		// 90.underlying_type
		cout << boolalpha << typeid(underlying_type<S3>::type).name() << " underlying_type " << endl;
		// 91.is_nothrow_swappable
		cout << boolalpha << is_nothrow_swappable<S3>::value << endl;
		// 92.is_nothrow_swappable_with
		cout << boolalpha << is_nothrow_swappable_with<S, S3>::value << endl;
		// 93.is_swappable
		cout << boolalpha << is_swappable<S>::value << endl;
		// 94.is_swappable_with
		cout << boolalpha << is_swappable_with<S, S3>::value << endl;
		// 95.false_type, true_type
		cout << "false_type == " << boolalpha << false_type::value << endl;
		cout << "true_type == " << boolalpha << true_type::value << endl;

		return true;
	}
}
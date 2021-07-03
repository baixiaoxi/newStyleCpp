#pragma once

#include "Fact.h"
#include <type_traits>
#include <vector>

namespace Function
{
	class Function final : public Fact {
	public:
		std::string name() override { return "Function"; }
		bool test() override;
	};

	constexpr float exp(float x, int n) {
		return n == 0 ? 1 : n % 2 == 0 ? exp(x * x, n / 2) : exp(x * x, (n - 1) / 2) * x;
	}

	extern "C" int printf(const char* fmt, ...);

	inline double efg()
	{
	}

	template<typename T>
	T copy_object(T& obj) noexcept(std::is_pod<T>) {
		return obj;
	}

	inline int foo(int i, std::string s) {
		int value{ i };
		if (s != "default") {
			value = 3;
		}

		return value;
	}
	// c++14
	template<typename Lhs, typename Rhs>
	decltype(auto) Add2(const Lhs& lhs, const Rhs& rhs)
	{
		return lhs + rhs;
	}

	inline int DoSomethingElse(int num, std::string str = std::string{ "Working" }) {

	}
	// trailing return types
	template<typename Lhs, typename Rhs>
	auto Add(const Lhs& lhs, const Rhs& rhs) -> decltype(lhs + rhs)
	{
		return lhs + rhs;
	}

	using namespace std;
	inline tuple<int, string, double> f()
	{
		int i{ 108 };
		string s{ "Some Text" };
		double d{ .01 };
		return { i, s, d };
	}

	typedef int (*fp)(int);
	fp myFunction(const char* s);

	int (*myFunction2(const char* s))(int);// 直接用函数名和参数列表替换fp

	void ShowVar(const char* szTypes, ...);

	// Ref qualifiers make it possible to overload a member function on the basis of whether the object pointed to by this is an rvalue or an lvalue
	class C
	{
	public:
		C() { }
		std::vector<unsigned> get_data()&
		{
			std::cout << "lvalue\n";
			return _data;
		}
		std::vector<unsigned> get_data()&&
		{
			std::cout << "rvalue\n";
			return std::move(_data);
		}
	private:
		std::vector<unsigned> _data;
	};

	// void call_with_true_double_only(float) = delete;
	// void call_with_true_double_only(double param) { ; }

	template<typename T>
	void call_with_true_double_only(T) = delete;// prevent call through type promotion of any T to double from succeeding
	inline void call_with_true_double_only(double param) { ; }// also define for const double, double&, etc, as needed

	struct widget
	{
		// deleted operator new prevents widget from being dynamically allocated.
		void* operator new(std::size_t) = delete;// 防止用new构造对象
	};
}
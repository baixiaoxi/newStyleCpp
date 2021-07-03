#pragma once

#include "Fact.h"
#include <vector>

class Template final : public Fact {
public:
	std::string name() override { return "Template"; }
	bool test() override;
};
// variadic template
// Types展开, parameter pack 和 parameters expansion
template<typename... Types> void func1(std::vector<Types...> v1)
{
	std::cout << "func1.argsNum = " << v1.size() << std::endl;
}
// 特例.在参数声明列表中，若...不是在模板parameter pack右侧，而在左侧，则也是parameter pack
// In a parameter-declaration-clause (func(parameter-list)), 
// a "top-level" ellipsis introduces a function parameter pack, 
// and the ellipsis positioning is important:
template<typename... Types> void func2(std::vector<Types>... v2)
{
	std::cout << "func2.argsNumber = " << sizeof...(v2) << std::endl;//
}
inline void print() {
	std::cout << std::endl;
}
template <typename T> void print(const T& t) {
	std::cout << t << std::endl;
}
template<typename First, typename... Rest> void print(const First& first, const Rest&... rest) {
	std::cout << first << ", ";
	print(rest...);// recursive call using pack expansion syntax
}

template<auto x> constexpr auto constant = x;

template<typename T, template<typename U, int I> class Arr>
class MyClass2
{
	T t;
	Arr<T, 10> a;
	// U u;// Error. U not in scope
};
template<typename T, template<typename, int> class Arr>
class MyClass3
{
	T t;
	Arr<T, 10> a;
};
// complete/partial specialization
template<typename K, typename V>
class MyMap{};

template<typename V>
class MyMap<std::string, V>{ };

template<class T> void f(T t);
template<> void f<char>(char c);
template<> void f(double d);

template<typename T> struct Allocator {
	template<typename U> struct Rebind {
		typedef Allocator<U> Other;
	};
};

template<typename X, typename AY> struct Container {
/*#if defined(NONCONFORMANT)
	typedef typename AY::Rebind<X>::Other AX;// nonconformant
#elif defined(CONFORMANT)
	typedef typename AY::template Rebind<X>::Other AX;// conformant
#else
	#error Define NONCONFORMANT or CONFORMANT
#endif
*/
	// Visual Studio 2012 enforces the C++98/03/11 standard rules for disambiguation with the "template" keyword.
	typedef typename AY::template Rebind<X>::Other AX;// conformant
};
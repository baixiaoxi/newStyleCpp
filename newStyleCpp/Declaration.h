#pragma once

#include "Fact.h"

class Declaration final : public Fact {
public:
	std::string name() override { return "Declaration"; }
	bool test() override;
private:
	int getMonth() const;
	void setMonth(int tmn);

	void g() {
		//[[using rpr: kernel, target(cpu, gpu)]] // equivalent to [[ rpr::kernel, rpr::target(cpu,gpu) ]]
		//do task();
		int arr[10];
		int* p = arr;
		[[gsl::suppress(bounds.1)]]
		{
			int* q = p + 1;
			p = q--;
		}
	}
};

thread_local __declspec(selectany) float declarationF = 42.0;
extern const __declspec(selectany) int i_ajo = 2;

constexpr float exp(float x, int n)
{
	return n == 0 ? 1 : n % 2 == 0 ? exp(x * x, n / 2) : exp(x * x, (n - 1) / 2) * x;
}

constexpr float z = exp(5, 3);


// You can specify thread_local only on data items with static storage duration
struct S
{
	// thread_local int i;// Illegal. The member must be static.
	thread_local static char buf[10];
};

inline void DoSomething()
{
	// Any local variable declared thread_local is implicitly static if no other storage class is provided; 
	// in other words, at block scope thread_local is equivalent to thread_local static.
	thread_local S my_struct;// Implicitly "thread_local static S my_struct".
}

extern "C" int printf(const char* fmp, ...);
extern "C" {
	char ShowChar(char ch);
	char GetChar(void);
}
extern "C" int errno;

struct MyAggregate1 {
	int myInt;
	char myChar = 'Z';
};

struct MyAggregate2 {
	int myInt;
	char myChar = 'Z';
	virtual void test() {// 有虚函数，导致无法使用Aggregate初始化

	}
};

struct MyAggregate3 {
	int myInt;
private: // no private or protected members
	char myChar = 'E';
};

struct MyAggregate4 {
	int myInt;
	char myChar = 'D';

	MyAggregate4(int vint) {// no user-provided constructors,except for explicitly defaulted or deleted constructors
		myInt = vint;
	}
};

struct MyAggregateBase {};
struct MyAggregate5 : public MyAggregateBase {// no base classes
	int myInt;
	char myChar = 'E';
};

using myInt = int;

typedef struct {
	unsigned x;
	unsigned y;
} POINT1;

class B {
public:
	void f(char) {
		printf_s("In B::f()\n");
	}
	void g(char) {
		printf_s("In B::g()\n");
	}
};

class D : B {
public:
	using B::f;
	using B::g;

	void f0(int) {
		printf_s("In D::f()\n");
		f('c');
	}
	void g0(int) {
		printf_s("In D::g()\n");
		g('c');
	}
};

//c++11
template<typename T, typename U>
auto myFunc(T&& t, U&& u) -> decltype(std::forward<T>(t) + std::forward<U>(u)) {
	return std::forward<T>(t) + std::forward<U>(u);
}

//c++14
template<typename T, typename U>
decltype(auto) myFunc(T&& t, U&& u) {
	return std::forward<T>(t) + std::forward<U>(u);
}
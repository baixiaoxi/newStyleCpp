#pragma once

#include "Fact.h"

namespace TrivialClz
{
	class TrivialClz final : public Fact {
	public:
		bool test() override;
		std::string name() override { return "Trivial"; }
	};

	struct Trivial1
	{
		int i;
	private:
		int j;
	};

	struct Trivial2
	{
		int i;
		Trivial2(int a, int b) : i(a), j(b) {}
		Trivial2() = default;
	private:
		int j;   // Different access control
	};

	struct Trivial3 : public Trivial1 {
	private:
		int mm;
	};

	struct StandardLayout1
	{
		// All members have same access:
		int i;
		int j;
		StandardLayout1(int a, int b) : i(a), j(b) {} // User-defined constructor OK
	};

	struct StandardLayout2
	{
		int i;
		int j;
	};

	// std::is_standard_layout<<Derived> == false!
	struct StandardLayout3 : public StandardLayout2
	{
		int x;
		int y;
	};

	struct StandardLayout4
	{
		void Foo() {}
	};

	// std::is_standard_layout<<Derived> == true
	struct StandardLayout5 : public StandardLayout4
	{
		int x;
		int y;
	};

	struct Pod1
	{
	protected:
		virtual void Foo() {}
	};

	// Neither trivial nor standard-layout
	struct Pod2 : Pod1
	{
		int a;
		int b;
		void Foo() override {} // Virtual function
	};

	// Trivial but not standard-layout
	struct Pod3
	{
		int a;
	private:
		int b;   // Different access control
	};

	// Standard-layout but not trivial
	struct Pod4
	{
		int a;
		int b;
		Pod4() {} //User-defined constructor
	};

	struct Pod5
	{
	private:
		int a;
		int b;
	};
}
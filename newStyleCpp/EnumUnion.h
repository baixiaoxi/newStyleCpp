#pragma once

#include "Fact.h"

namespace EnumUnion
{
	class EnumUnion final : public Fact {
	public:
		std::string name() override { return "EnumUnion"; }
		bool test() override;
	};

	// By defining an enum (regular or scoped) with an explicit underlying type and no enumerators,
	// you can in effect introduce a new integral type that has no implicit conversion to any other type. 
	// By using this type instead of its built-in underlying type, you can eliminate the potential for 
	// subtle errors caused by inadvertent implicit conversions.
	enum class byte : unsigned char { };

	enum class E : int { };

	struct X {
		E e{ 0 };
		X() :e{ 0 } {}
	};

	inline void f(E e) {};

	/*
	E e1{ 0 };
	E e2 = E{ 0 };
	E* p = new E{ 0 };
	*/

	// You cannot declare the members of a union as static. 
	// However, a globally declared anonymous union must be explicitly declared static
	// 要不然就重复定义了，必须搞成internal linkage
	static union {
		int abc;
		long efg;
	};

	union RecordType
	{
		char ch;
		int i;
		long l;
		float f;
		double d;
		int* int_ptr;
	};

	// 类型
	struct A
	{
	private:
		int num;
		std::string name;
	};

	// If the union is an anonymous union inside a class or struct, then any special member functions of
	// the class or struct that aren't user provided are marked as deleted
	// Union如果是匿名的在类或结构体中，那么该类或结构体的特殊函数都标记为deleted
	class MyVariant
	{
	public:
		MyVariant() {// 默认标记删除，必须要手动提供特殊函数

		}

		~MyVariant() {// 默认标记删除，必须要手动提供特殊函数

		}

	private:
		union// 1.匿名
		{
			int i;
			A a;// 2.包含了class或struct类型的非静态数据成员，所在类的默认函数标记删除
			char c;
		};
	};

}
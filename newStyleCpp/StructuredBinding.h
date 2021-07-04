#pragma once

#include "Fact.h"
#include <utility>
#include <type_traits>

// 看起来，microsoft c++，只要成员是public就可以直接绑定，不需要额外的操作
/////////////////////////////////////////////////////
// 参考: https://devblogs.microsoft.com/oldnewthing/20201015-00/?p=104369
//#支持structured bind的要素 :[在microsoft vc++试验无效]
// > 1.特化std::tuple_size<T>，指定类型的绑定数量
// > 2.特化tuple_element<Index, T>，指定绑定对应的类型
// > 3.实现类成员函数get或全局函数get, 返回指定索引对应的值
// > 4.可以返回引用类型，也可以是值类型，按需要决定
/////////////////////////////////////////////////////

namespace StructuredBinding
{
	class StructuredBinding : public Fact
	{
	public:
		std::string name() override { return "StructuredBinding"; }
		bool test() override;
	};
	// 基类
	class Person
	{
	public:
		std::string name;
		int age;
	};
	// get是成员函数，不返回引用类型值
	class Person1 : public Person
	{
	public:
		std::string CalculateName() const { return "hello"; }
		int CalculateAge() const { return 1; }

		template<std::size_t Index>
		auto get() const
		{
			static_assert(Index < 3, "Index out of bounds for Custom::Person");

			if constexpr (Index == 0) return CalculateName();
			if constexpr (Index == 1) return CalculateAge();
			if constexpr (Index == 2) return CalculateAge();
		}
	};
	// get是成员函数, p.get<0>()
	class Person2 : public Person
	{
	public:
		std::string name;
		int age;

		template<std::size_t Index>
		std::tuple_element_t<Index, Person>& get()&
		{
			if constexpr (Index == 0) return name;
			if constexpr (Index == 1) return age;
		}

		template<std::size_t Index>
		std::tuple_element_t<Index, Person> const& get() const&
		{
			if constexpr (Index == 0) return name;
			if constexpr (Index == 1) return age;
		}

		template<std::size_t Index>
		std::tuple_element_t<Index, Person>& get()&&
		{
			if constexpr (Index == 0) return std::move(name);
			if constexpr (Index == 1) return std::move(age);
		}

		template<std::size_t Index>
		std::tuple_element_t<Index, Person> const& get() const&&
		{
			if constexpr (Index == 0) return std::move(name);
			if constexpr (Index == 1) return std::move(age);
		}
	};
	// get是成员函数, 添加一个辅助函数, p.get<0>()
	class Person3 : public Person
	{
	public:
		std::string name;
		int age;

		template<std::size_t Index>
		std::tuple_element_t<Index, Person>& get()&
		{
			return get_helper<Index>(*this);
		}

		template<std::size_t Index>
		std::tuple_element_t<Index, Person> const& get() const&
		{
			return get_helper<Index>(*this);
		}

		template<std::size_t Index>
		std::tuple_element_t<Index, Person>& get()&&
		{
			return get_helper<Index>(*this);
		}

		template<std::size_t Index>
		std::tuple_element_t<Index, Person> const& get() const&&
		{
			return get_helper<Index>(*this);
		}
	private:
		template<std::size_t Index, typename T>
		auto&& get_helper(T&& t)
		{
			static_assert(Index < 2, "Index out of bounds for Custom::Person");
			if constexpr (Index == 0) return std::forward<T>(t).name;
			if constexpr (Index == 1) return std::forward<T>(t).age;
		}
	};
	// get是全局函数, get<0>(p)
	class Person4 : public Person
	{
	public:
		std::string name;
		int age;
	};

	template<std::size_t Index, typename T>
	auto&& Person4_get_helper(T&& p)
	{
		static_assert(Index < 2, "Index out of bounds for Custom::Person");
		if constexpr (Index == 0) return std::forward<T>(p).name;
		if constexpr (Index == 1) return std::forward<T>(p).age;
	}

	template<std::size_t Index>
	auto&& get(Person4& p)
	{
		return Person4_get_helper<Index>(p);
	}

	template<std::size_t Index>
	auto&& get(Person4 const& p)
	{
		return Person4_get_helper<Index>(p);
	}

	template<std::size_t Index>
	auto&& get(Person4&& p)
	{
		return Person4_get_helper<Index>(std::move(p));
	}

	template<std::size_t Index>
	auto&& get(Person4 const&& p)
	{
		return Person4_get_helper<Index>(std::move(p));
	}
}

//structured binding
namespace std
{
	using Person = StructuredBinding::Person;
	// 1.指定绑定的数量
	// 方式1
	/*template<>
	struct tuple_size<Person>
	{
		static constexpr size_t value = 2;
	};*/

	// 方式2
	template<>
	struct tuple_size<Person> : integral_constant<size_t, 2> {};

	// 2.指定绑定的类型
	// 方式1, 没有范围检查
	/*template<>
	struct tuple_element<0, Person>
	{
		using type = std::string;
	};

	template<>
	struct tuple_element<1, Person>
	{
		using type = int;
	};

	// 方式2，有范围检查
	template<size_t Index>
	struct tuple_element<Index, Person> : conditional<Index == 0, std::string, int>
	{
		static_assert(Index < 2, "Index out of bounds for Person");
	};*/

	// 方式3，有范围检查
	template<size_t Index>
	struct tuple_element<Index, Person> : tuple_element<Index, tuple<string, int>>
	{

	};
}

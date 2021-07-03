#pragma once

#include "Fact.h"
#include <vector>

namespace Clz
{
	class Clz final : public Fact {
	public:
		std::string name() override { return "Clz"; }
		bool test() override;
	};

	class Box {
	public:
		Box(int width, int length, int height) : m_width(width), m_length(length), m_height(height) {}
		// copy constructors
		// When you define a copy constructor, you should also define a copy assignment operator (=)
		Box(Box& other) = delete;
		Box(const Box& other);
		Box(volatile Box& other);
		Box(volatile const Box& other);
		Box(Box& other, int i = 42, std::string label = "Box");
		// move constructors
		Box(Box&& other) noexcept
		{
			// 复用move assignment operator，减少冗余代码
			*this = std::move(other);// std::move是使other变右值
			std::cout << "move" << std::endl;
		}
		// move assignment
		Box& operator=(Box&& other)
		{
			if (this != &other) {// 判断是否自己，防止释放自身资源
				m_width = other.m_width;
				m_height = other.m_height;
				m_length = other.m_length;
				m_contents = std::move(other.m_contents);
			}

			return *this;
		}
		// explicit
		explicit Box(int size) : m_width(size), m_length(size), m_height(size) {}
		// 
		int Volume() { return m_width * m_height * m_length; }
		void Add_Item(std::string item) { m_contents.push_back(item); }
		void Print_Contents()
		{
			for (const auto& item : m_contents)
			{
				std::cout << item << " ";
			}
		}
	private:
		int m_width{ 0 };
		int m_length{ 0 };
		int m_height{ 0 };
		std::vector<std::string> m_contents;
	};

	class Base
	{
	public:
		Base() { std::cout << "Base()" << std::endl; }
		Base(const Base& other) { std::cout << "Base(Base&)" << std::endl; }
		explicit Base(int i) : num(i) { std::cout << "Base(int)" << std::endl; }
		explicit Base(char c) : letter(c) { std::cout << "Base(char)" << std::endl; }
	private:
		int num;
		char letter;
	};

	class Derived : Base
	{
	public:
		// Inherit all constructors from Base
		using Base::Base;
	private:
		// Can't initialize newMember from Base constructors
		int newMember{ 0 };
	};
	class X
	{
	public:
		bool GetFlag() const {
			m_accessCount++;
			return m_flag;
		}
	private:
		bool m_flag;
		mutable int m_accessCount;// mutable，即使const函数也能修改
	};

	struct phone
	{
		int areacode;
		long number;
	};

	struct person
	{
		char name[30];
		char gender;
		int age;
		int weight;
		struct phone;// Anonymous structure; no name needed
	};
}

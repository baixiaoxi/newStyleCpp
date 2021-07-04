#pragma once

#include "Fact.h"
#include <vector>
#include <algorithm>

class Pointer final : public Fact {
public:
	bool test() override;
	std::string name() override { return "Pointer"; }
};

class A
{
public:
	int i;
	int m;
};

//std::string(*g)(std::string a);
//void (*x)();
//int (*i)(int i, std::string s, double d);

std::string append(std::string s);
std::string prepend(std::string s);
std::string combine(std::string s, std::string(*g)(std::string a));

struct X {
	X(int i) : m_i(i) { }
	int m_i;
};

class MyClass
{
public:
	void* operator new[](size_t)
	{
		return 0;
	}
		void operator delete[](void*)
	{

	}
};

struct MediaAsset
{
	virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
	std::wstring artist;
	std::wstring title;
	Song(const std::wstring& artist_, const std::wstring& title_)
		: artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
	std::wstring date;
	std::wstring location;
	std::wstring subject;
	Photo(const std::wstring& date_, const std::wstring& location_, const std::wstring& subject_)
		: date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

class Controller
{
public:
	int Num;
	std::wstring Status;
	std::vector<std::weak_ptr<Controller>> others;

	explicit Controller(int i) : Num(i), Status(L"On")
	{
		std::wcout << L"Creating Controller" << Num << std::endl;
	}

	~Controller()
	{
		std::wcout << L"Destroying Controller" << Num << std::endl;
	}

	void CheckStatuses() const
	{
		std::for_each(others.begin(), others.end(), [](std::weak_ptr<Controller> wp) {
			auto p = wp.lock();
			if (p)
			{
				std::wcout << L"Status of " << p->Num << " = " << p->Status << std::endl;
			}
			else
			{
				std::wcout << L"Null object" << std::endl;
			}
			});
	}
};


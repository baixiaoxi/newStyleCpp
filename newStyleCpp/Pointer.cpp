#include "Pointer.h"
#include <vector>
#include <algorithm>

bool Pointer::test() {
	A a = { 1, 2 };
	int A::* pai = 0;
	pai = &A::i;

	std::cout << a.*pai << std::endl;
	std::nullptr_t t = nullptr;
	std::cout << "typeid(nullptr).name=" << typeid(nullptr).name() << std::endl;

	std::cout << combine("from MSVC", append) << "\n";
	std::cout << combine("Good moring and", prepend) << "\n";
	// unique_ptr
	std::unique_ptr<MyClass> smartPtr(new MyClass());
	std::unique_ptr smartPtr2 = std::make_unique<MyClass>();
	auto rawPtr = smartPtr2.get();// get the raw pointer
	smartPtr = std::move(smartPtr2);// 只能move，不能拷贝(补删了)
	smartPtr2.reset();
	smartPtr.reset();// Free the memory before exit function block
	auto p = std::make_unique<int[]>(5);
	// shared_ptr
	auto sp1 = std::make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");
	std::shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));
	std::shared_ptr<Song> sp5(nullptr);
	sp5 = std::make_shared<Song>(L"Elton John", L"I'm Still Standing");
	auto sp3(sp2);
	auto sp4 = sp2;
	std::shared_ptr<Song> sp7(nullptr);
	sp1.swap(sp2);// swap pointers as well as ref counts
	std::vector<std::shared_ptr<Song>> v{
		std::make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
		std::make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
		std::make_shared<Song>(L"Thalía", L"Entre El Mar y Una Estrella")
	};
	std::vector<std::shared_ptr<Song>> v2;
	std::remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](std::shared_ptr<Song> s) {
		return s->artist.compare(L"Bob Dylan") == 0;
		});

	for (const auto& s : v2) {
		std::wcout << s->artist << L":" << s->title << std::endl;
	}

	std::vector<std::shared_ptr<MediaAsset>> assets{
		std::make_shared<Song>(L"Himesh Reshammiya", L"Tera Surroor"),
		std::make_shared<Song>(L"Penaz Masani", L"Tu Dil De De"),
		std::make_shared<Photo>(L"2011-04-06", L"Redmond, WA", L"Soccer field at Microsoft.")
	};

	std::vector<std::shared_ptr<MediaAsset>> photos;
	std::copy_if(assets.begin(), assets.end(), back_inserter(photos), [](std::shared_ptr<MediaAsset> p) -> bool
	{
		std::shared_ptr<Photo> temp = std::dynamic_pointer_cast<Photo>(p);
		return temp.get() != nullptr;
	});

	for (const auto& p : photos)
	{
		// We know that the photos vector contains only 
		// shared_ptr<Photo> objects, so use static_cast.
		std::wcout << "Photo location: " << (std::static_pointer_cast<Photo>(p))->location << std::endl;
	}
	auto song1 = new Song(L"Village People", L"YMCA");
	auto song2 = new Song(L"Village People", L"YMCA");
	std::shared_ptr<Song> p1(song1);
	std::shared_ptr<Song> p2(song2);
	std::wcout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << std::endl;
	std::wcout << "p1 == p2 = " << std::boolalpha << (p1 == p2) << std::endl;
	std::shared_ptr<Song> p3(p2);
	std::wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << std::endl;
	// weak_ptr
	RunTest();

	MyClass* mc = new MyClass[5];
	delete[] mc;

	return true;
}
// To declare the object pointed to by the pointer as const or volatile
// 指针指向的对象是const或volatile
const char* cpch;
volatile char* vpch;
// To declare the value of the pointer — that is, the actual address stored in the pointer — as const or volatile,
// 指针本身是const或volatile
//char* const pchc;
char* volatile pchv;
//
const char cch = 'A';
char ch = 'B';
const char* pch1 = &cch;
const char* const pch4 = &cch;
const char* pch5 = &ch;
char* pch6 = &ch;
char* const pch7 = &ch;
const char* const pch8 = &ch;

std::string base{ "hello world" };

std::string append(std::string s)
{
	return base.append(" ").append(s);
}

std::string prepend(std::string s)
{
	return s.append(" ").append(base);
}

std::string combine(std::string s, std::string(*g)(std::string a))
{
	return (*g)(s);
}

const X cx(10);
const X* pcx = &cx;
const X** ppcx = &pcx;

X const cx2(20);
X const* pcx2 = &cx2;
X const** ppcx2 = &pcx2;
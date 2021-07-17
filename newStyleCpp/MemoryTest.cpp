#include "MemoryTest.h"
#include <memory>
#include <memory_resource>

namespace MemoryTest
{
	using namespace std;

	class Integer
	{
	public:
		Integer(int x) : value(x) {}
		int get() { return value; }
	private:
		int value;
	};

	struct base
	{
		virtual ~base() {}
		int value;
	};

	struct derived : public base
	{

	};

	struct deleter
	{
		void operator()(base* pb)
		{
			delete pb;
		}
	};

	class Animal
	{
	private:
		std::wstring genus;
		std::wstring species;
		int age;
		double weight;
	public:
		Animal(const wstring&, const wstring&, int, double) {/*...*/ }
		Animal() {}
	};

	bool MemoryTest::test()
	{
		char buffer[256]; // for simplicity
		size_t alignment = alignment_of<int>::value;
		void* ptr = buffer;
		size_t space = sizeof(buffer); // Be sure this results in the true size of your buffer

		while (align(alignment, sizeof(int), ptr, space)) {
			// You now have storage the size of MyObj, starting at ptr, aligned on
			// int boundary. Use it here if you like, or save off the starting address
			// contained in ptr for later use.
			// ...
			// Last, move starting pointer and decrease available space before
			// the while loop restarts.
			ptr = reinterpret_cast<char*>(ptr) + sizeof(int);
			space -= sizeof(int);
		}

		// 1.address_of
		{
			int ival;
			int* ip = addressof(ival);
		}
		// 2.align
		{
			void* startPtr = nullptr;
			size_t spaceSize = 55;
			bool result = align(8, 8, startPtr, spaceSize);
		}
		// 3.allocate_shared
		// 4.atomic_compare_exchange_strong
		// 5.atomic_compare_exchange_weak
		// 6.atomic_compare_exchange_strong_explicit
		// 7.atomic_compare_exchange_weak_explicit
		// 8.atomic_exchange
		// 9.atomic_exchange_explicit
		// 10.atomic_is_lock_free
		// 11.atomic_load
		// 12.atomic_load_explicit
		// 13.atomic_store
		// 14.atomic_store_explicit
		// 15.const_pointer_cast
		{
			shared_ptr<int> sp0(new int);
			shared_ptr<const int> sp1 = const_pointer_cast<const int>(sp0);
			*sp0 = 3;
			cout << "sp1 == " << *sp1 << endl;
		}
		// 16.declare_no_pointers
		// 17.declare_reachable
		// 18.default_delete
		// 19.destroy_at
		// 20.destroy
		// 21.destroy_n
		// 22.dynamic_pointer_cast
		{
			shared_ptr<base> sp0(new derived);
			shared_ptr<derived> sp1 = dynamic_pointer_cast<derived>(sp0);
			sp0->value = 3;
			cout << "sp1->value == " << sp1->value << endl;
		}
		// 23.get_deleter
		{
			shared_ptr<base> sp0(new base);
			sp0->value = 3;
			cout << "get_deleter(sp0) != 0 == " << boolalpha << (get_deleter<deleter>(sp0) != 0) << endl;
			shared_ptr<base> sp1(new base, deleter());
			sp0->value = 3;
			cout << "get_deleter(sp1) != 0 == " << boolalpha << (get_deleter<deleter>(sp1) != 0) << endl;
		}
		// 24.get_pointer_safety
		// 25.get_temporary_buffer
		// 26.make_shared
		// 27.make_unique
		{
			// Use the Animal default constructor.
			unique_ptr<Animal> p1 = make_unique<Animal>();
			// Use the constructor that matches these arguments
			auto p2 = make_unique<Animal>(L"Felis", L"Catus", 12, 16.5);
			// Create a unique_ptr to an array of 5 Animals
			unique_ptr<Animal[]> p3 = make_unique<Animal[]>(5);
			// Initialize the elements
			p3[0] = Animal(L"Rattus", L"norvegicus", 3, 2.1);
			p3[1] = Animal(L"Corynorhinus", L"townsendii", 4, 1.08);
			// auto p4 = p2; //C2280
			vector<unique_ptr<Animal>> vec;
			// vec.push_back(p2); //C2280
			// vector<unique_ptr<Animal>> vec2 = vec; // C2280
			// OK. p2 no longer points to anything
			vec.push_back(std::move(p2));
			// unique_ptr overloads operator bool
			// wcout << boolalpha << (p2 == false) << endl; // Prints "true"
			// OK but now you have two pointers to the same memory location
			Animal* pAnimal = p2.get();
			// OK. p2 no longer points to anything
			Animal* p5 = p2.release();
		}
		// 28.owner_less
		{

		}
		// 29.reinterpret_pointer_cast
		// 30.return_temporary_buffer
		{
			int intArray[] = { 10, 20, 30, 40, 100, 200, 300 };
			int cout = sizeof(intArray) / sizeof(int);
			pair<int*, ptrdiff_t> resultPair;
			//resultPair = get_temporary_buffer<int>(count);
			int* tempBuffer = resultPair.first;
			//return_temporary_buffer(tempBuffer);
		}
		// 31.static_pointer_cast
		{
			shared_ptr<base> sp0(new derived);
			shared_ptr<derived> sp1 = static_pointer_cast<derived>(sp0);
			sp0->value = 3;
			cout << "sp1->value == " << sp1->value << endl;
		}
		// 32.swap
		{
			shared_ptr<int> sp1(new int(5));
			shared_ptr<int> sp2(new int(10));
			sp1.swap(sp2);
			swap(sp1, sp2);
		}
		// 33.undeclare_no_pointers
		// 34.undeclare_reachable
		// 35.uninitialized_copy
		{
			int Array[] = { 10, 20, 30, 40 };
			const int N = sizeof(Array) / sizeof(int);
			Integer* ArrayPtr = (Integer*)malloc(N * sizeof(int));
			Integer* LArrayPtr = uninitialized_copy(Array, Array + N, ArrayPtr);
			free(ArrayPtr);
		}
		// 36.uninitialized_copy_n
		// 37.uninitialized_default_construct
		// 38.uninitialized_default_construct_n
		// 39.uninitialized_fill
		{
			const int N = 10;
			Integer value(25);
			Integer* Array = (Integer*)malloc(N * sizeof(int));
			uninitialized_fill(Array, Array + N, value);
			cout << "The initialized Array contains: ";
			for (int i = 0; i < N; ++i)
			{
				cout << Array[i].get() << " ";
			}
			cout << endl;
		}
		// 40.uninitialized_fill_n
		{
			const int N = 0;
			Integer value(60);
			Integer* Array = (Integer*)malloc(N * sizeof(int));
			uninitialized_fill_n(Array, N, value);
			cout << "The uninitialized Array contains: ";
			for (int i = 0; i < N; ++i)
			{
				cout << Array[i].get() << " ";
			}
		}
		// 41.uninitialized_move
		// 42.uninitialized_move_n
		// 43.uninitialized_value_construct
		// 44.uninitialized_value_construct_n
		// 45.uses_allocator_v
		// 46.


		return true;
	}
}
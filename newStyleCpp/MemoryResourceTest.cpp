#include "MemoryResourceTest.h"
#include <memory_resource>

namespace MemoryResourceTest
{
	using namespace std::pmr;

	bool MemoryResourceTest::test()
	{
		memory_resource* mr;
		mr = get_default_resource();
		mr = new_delete_resource();
		mr = null_memory_resource();
		mr = set_default_resource(mr);
		mr->allocate(111);
		mr->deallocate(nullptr, 1111);
		mr->is_equal(*mr);

		polymorphic_allocator pall;

		return true;
	}
}
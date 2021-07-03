#include "Move.h"

namespace Move
{
	void g(const MemoryBlock&)
	{
		std::cout << "In g(const MemoryBlock&)." << std::endl;
	}

	void g(MemoryBlock&&)
	{
		std::cout << "In g(MemoryBlock&&)." << std::endl;
	}

	bool Move::test()
	{
		MemoryBlock block;
		g(block);
		g(static_cast<MemoryBlock&&>(block));
		g(std::move(block));

		return true;
	}
}
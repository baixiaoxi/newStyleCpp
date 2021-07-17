#include "TrivialClz.h"

namespace TrivialClz
{
	template<typename T>
	bool is_pod()
	{
		return std::is_standard_layout_v<T> && std::is_trivial_v<T>;
	}

	bool TrivialClz::test() {

		std::cout << "Trivial1 is trivial:" << (std::is_trivial<Trivial1>() ? "true" : "false") << std::endl;
		std::cout << "Trivial2 is trivial:" << (std::is_trivial<Trivial2>() ? "true" : "false") << std::endl;
		std::cout << "Trivial3 is trivial:" << (std::is_trivial<Trivial3>() ? "true" : "false") << std::endl;

		std::cout << "StandardLayout1 is standard layout:" << (std::is_standard_layout_v<StandardLayout1> ? "true" : "false") << std::endl;
		std::cout << "StandardLayout2 is standard layout:" << (std::is_standard_layout_v<StandardLayout2> ? "true" : "false") << std::endl;
		std::cout << "StandardLayout3 is standard layout:" << (std::is_standard_layout_v<StandardLayout3> ? "true" : "false") << std::endl;
		std::cout << "StandardLayout4 is standard layout:" << (std::is_standard_layout_v<StandardLayout4> ? "true" : "false") << std::endl;
		std::cout << "StandardLayout5 is standard layout:" << (std::is_standard_layout_v<StandardLayout5> ? "true" : "false") << std::endl;

		std::cout << "Pod1 is pod:" << (is_pod<Pod1>() ? "true" : "false") << std::endl;
		std::cout << "Pod2 is pod:" << (is_pod<Pod2>() ? "true" : "false") << std::endl;
		std::cout << "Pod3 is pod:" << (is_pod<Pod3>() ? "true" : "false") << std::endl;
		std::cout << "Pod4 is pod:" << (is_pod<Pod4>() ? "true" : "false") << std::endl;
		std::cout << "Pod5 is pod:" << (is_pod<Pod5>() ? "true" : "false") << std::endl;

		return true;
	}
}
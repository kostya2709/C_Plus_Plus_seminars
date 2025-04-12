#include <iostream>
#include <tuple>
#include <type_traits>

std::string universe() {
	return "universe";
}
	
int main() { 
	int i = 42; 
	auto myTuple = std::forward_as_tuple(i, universe());
	static_assert(std::is_same_v<decltype(myTuple), std::tuple<int&, std::string&&>>);
}

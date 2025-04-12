#include <tuple>
#include <iostream>

int main() {
	std::tuple<int, int> tup1{1, 2};
	std::cout << std::get<0>(tup1) << ' ' << std::get<1>(tup1) << '\n';
	
	auto tup2 = std::make_tuple(1, 2);
	std::cout << std::get<0>(tup2) << ' ' << std::get<1>(tup2) << '\n';

	std::tuple tup3{1, 2};
	std::cout << std::get<0>(tup3) << ' ' << std::get<1>(tup3) << '\n';
}

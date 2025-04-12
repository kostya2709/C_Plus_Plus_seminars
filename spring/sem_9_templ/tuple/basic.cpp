#include <iostream>
#include <iostream>

int main() {

	std::tuple test{1, 'c', 0.0};
	
	auto& lref = std::get<0>(test);
	auto&& rref = std::get<int>(std::move(test));

	auto&& [x, y, z] = std::move(test);

}

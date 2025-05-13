#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdint>

void dump(const std::vector<auto>& vec) {
	for (const auto& elem : vec) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}

int main() {

	std::vector<int> vec1{1, 2, 3, 4};
	std::vector<uint64_t> vec2{1, 2, 3, 4};

	auto mul2 = [](auto& x) {
		x *= 2;
	};

	std::for_each(vec1.begin(), vec1.end(), mul2);
	std::for_each(vec2.begin(), vec2.end(), mul2);
	
	dump(vec1);
	dump(vec2);
}

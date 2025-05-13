#include <iostream>
#include <vector>
#include <algorithm>


int main() {
	std::vector<int> vec{1, 4, 9, 12, 0};

	auto cmp = [](int x, int y) { return x > y; };

	std::sort(vec.begin(), vec.end(), cmp);
	
	for (auto elem : vec) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}

#include <iostream>
#include <vector>
#include <algorithm>

void dump(std::vector<int>& vec) {
	for (auto elem : vec) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}


int main() {
	std::vector<int> vec{1, 4, 9, 12, 0};

	bool invert = false;
	size_t counter{0};
	auto cmp = [invert=!invert, &counter](int x, int y) mutable {
		++counter;
		return invert ? x < y : x > y;
	};

	std::sort(vec.begin(), vec.end(), cmp);
	dump(vec);
	std::cout << "Counter: " << counter << '\n';
}

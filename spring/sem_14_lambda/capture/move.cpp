#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

void dump(std::vector<int>& vec) {
	for (auto elem : vec) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}

int main() {
	std::vector<int> vec{1, 4, 9, 12, 0};

	std::unique_ptr<bool> invert = std::make_unique<bool>(false);
	size_t counter{0};
	auto cmp = [invert=std::move(invert), &counter](int x, int y) mutable {
		++counter;
		return *invert ? x < y : x > y;
	};

	std::sort(vec.begin(), vec.end(), std::move(cmp));
	dump(vec);
	std::cout << "Counter: " << counter << '\n';
}

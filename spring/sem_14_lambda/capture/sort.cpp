#include <iostream>
#include <vector>
#include <algorithm>


int main() {
	std::vector<int> vec{1, 4, 9, 12, 0};

	bool invert = false;
	auto cmp = [invert](int x, int y) {
		return invert ? x < y : x > y;
	};

	invert = true;

	std::sort(vec.begin(), vec.end(), cmp);
	
	for (auto elem : vec) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}

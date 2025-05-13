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
	auto cmp = [&invert](int x, int y) {
		return invert ? x < y : x > y;
	};

	std::sort(vec.begin(), vec.end(), cmp);
	dump(vec);
	
	invert = true;

	std::sort(vec.begin(), vec.end(), cmp);
	dump(vec);	
}

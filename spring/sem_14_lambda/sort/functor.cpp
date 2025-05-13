#include <iostream>
#include <vector>
#include <algorithm>

struct Comparator {
	bool operator()(int x, int y) {
		return x > y;
	}
};

int main() {
	std::vector<int> vec{1, 4, 9, 12, 0};
	std::sort(vec.begin(), vec.end(), Comparator());
	
	for (auto elem : vec) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}

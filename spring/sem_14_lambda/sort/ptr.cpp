#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int x, int y) {
	return x > y;
}

int main() {
	std::vector<int> vec{1, 4, 9, 12, 0};
	std::sort(vec.begin(), vec.end(), compare);
	
	for (auto elem : vec) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}

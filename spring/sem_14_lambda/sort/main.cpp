#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> vec{1, 4, 9, 12, 0};
	std::sort(vec.begin(), vec.end());
	
	for (auto elem : vec) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}

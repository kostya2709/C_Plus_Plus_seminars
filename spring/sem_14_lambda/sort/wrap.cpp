#include <iostream>
#include <vector>
#include <algorithm>

struct Wrapper {
	Wrapper(int x) : value(x) {}
	int value;
};
	
bool operator<(const Wrapper& x, const Wrapper& y) {
	return x.value > y.value;
}


int main() {
	std::vector<Wrapper> vec{1, 4, 9, 12, 0};
	std::sort(vec.begin(), vec.end());
	
	for (auto elem : vec) {
		std::cout << elem.value << ' ';
	}
	std::cout << '\n';
}

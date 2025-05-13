#include <iostream>


int main() {
	auto cmp = *[](int x, int y) { return x < y; };
	bool less = cmp(1, 2);

	std::cout << "sizeof(cmp) = " << sizeof(cmp) << '\n';
}

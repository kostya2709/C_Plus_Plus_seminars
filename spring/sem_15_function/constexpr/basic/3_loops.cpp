#include <iostream>

constexpr int sum(int x) {
	int sum = 0;
	for (int i = 0; i <= x; ++i) {
		sum += i;
	}
	return sum;
}


int main() {

	static_assert(sum(3) == 6);
}

#include <iostream>

int sum(int x, int y) {
	return x + y;
}

namespace A {
	int var = 0;
};

namespace B {
	int var = 1;
};

using namespace A;
using namespace B;

int main() {
	float x = 0;
	float y = x << 2;
	int x = "123" * 2;

	sum(1);

	std::cout << var << '\n';
}

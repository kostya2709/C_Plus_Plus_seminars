#include <iostream>


int main() {

	auto fac = [](this auto&& self, size_t n) -> size_t {
		if (n == 0) {
			return 1;
		}
		return n * self(n - 1);
	};

	std::cout << fac(3) << '\n';

}

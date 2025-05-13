#include <iostream>


int main() {

	auto fac = [](size_t n) {
		if (n == 0) {
			return 1;
		}
		return fac(n - 1);
	};

	std::cout << fac(3) << '\n';

}

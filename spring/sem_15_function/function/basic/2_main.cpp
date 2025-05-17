#include <functional>
#include <iostream>


int main() {

	int counter{0};
	auto cmp_lambda = [&counter](int x, int y) {
		++counter;
		return x < y;
	};

	std::function<bool(int, int)> cmp(cmp_lambda);

	std::cout << cmp(1, 2) << '\n';

	auto cmp2 = cmp;
	std::cout << cmp2(1, 2) << '\n';

	auto cmp3 = std::move(cmp2);
	std::cout << cmp3(1, 2) << '\n';

	std::cout << "Counter: " << counter << '\n';

}


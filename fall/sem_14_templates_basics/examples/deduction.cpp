#include <iostream>

template <typename T>
T max(T a, T b) {
	return a > b ? a : b;
}

int main() {

	int x = 0;
	int y = 1;
	std::cout << "max(x, y) = " << max(x, y) << '\n';

	float fx = 0;
	float fy = 1;
	std::cout << "max(fx, fy) = " << max(fx, fy) << '\n';

	std::cout << "max(x, fy) = " << max(x, fy) << '\n';

}

#include <iostream>

template <typename T>
requires requires (T a, T b) { a * b; }
T mul(const T& a, const T& b) {
	return a * b;
}

int main() {

	std::cout << "Requires: " << requires (int x, int y){ x + y; } << '\n';

	mul(1, 2);
	mul(nullptr, nullptr);

}

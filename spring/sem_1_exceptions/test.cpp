
#include <iostream>

int divide(int a, int b) {
	return a / b;
}

int main() {
	int d = divide(1, 0);
	std::cout << d << '\n';
}

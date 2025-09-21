#include <iostream>

int f() {
	std::cout << "f\n";
	return 1;
}

int g() {
	std::cout << "g\n";
	return 2;
}

int h() {
	std::cout << "h\n";
	return 3;
}

int main() {

	int x = f() + g() * h();
	std::cout << "x = " << x << '\n';
}


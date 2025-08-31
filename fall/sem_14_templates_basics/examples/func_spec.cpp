#include <iostream>

template <typename T, typename U>
void foo(T a, U b) {
	std::cout << "foo(T, U)\n";
}

template <typename T>
void foo(T a, T b) {
	std::cout << "foo(T, T)\n";
}

template <>
void foo(int a, int b) {
	std::cout << "foo<>(int, int)\n";
}

/*
void foo(int a, int b) {
	std::cout << "foo(int, int)\n";
}
*/

int main() {

	foo(0, 1);

}

#include <iostream>

constexpr int value = 42;

void foo() requires (value == 42) {
	std::cout << "Really 42\n";
}

void foo() {
	std::cout << "Not really 42\n";
}

int main() {

	foo();

}

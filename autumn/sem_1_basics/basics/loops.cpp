#include <iostream>

int main() {

	// For loop
	for (int i = 0; i < 5; ++i) {
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	// While loop
	int value = 5;
	while (value > 0) {
		--value;
		std::cout << value << ' ';
	}

	std::cout << std::endl;

	// Do-while loop
	do {
		std::cout << value << ' ';
		++value;
	} while (value < 5);

	std::cout << std::endl;
}



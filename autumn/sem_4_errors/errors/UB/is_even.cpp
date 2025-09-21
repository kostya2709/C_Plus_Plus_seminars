#include <iostream>


int main() {

	unsigned int i = 0;
	do {
		i+=2;
	} while (0==(i&1));

	std::cout << "Done\n";

}

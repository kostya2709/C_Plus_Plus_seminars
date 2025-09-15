#include <iostream>

void useful_func();

int important_func() {
	std::cout << "important func\n";
	int x = 1;
	useful_func();
	return x;
}


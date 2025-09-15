#include <iostream>
#include "my_lib.cpp"

int important_func() {
	std::cout << "important func\n";
	int x = 1;
	useful_func();
	return x;
}


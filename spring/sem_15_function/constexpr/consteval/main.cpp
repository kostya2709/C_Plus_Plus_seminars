#include <iostream>

consteval int foo(int x) {
	return 2 * x;
}

int main() {

	int input = 0;
	std::cin >> input;
	
	foo(1);
	foo(input);	
}



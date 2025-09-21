#include <iostream>

void foo(int x, int y) {
	std::cout << x << ' ' << y << '\n';
}


int main() {

	int x = 0;
	foo(++x, ++x);

}


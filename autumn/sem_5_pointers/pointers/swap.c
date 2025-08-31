#include <iostream>

void swap(int x, int y) {
	int tmp = x;
	x = y;
	y = tmp;
}


int main() {
	int x = 1;
	int y = 2;

	swap(x, y);

	std::cout << x << ' ' << y << std::endl;

}

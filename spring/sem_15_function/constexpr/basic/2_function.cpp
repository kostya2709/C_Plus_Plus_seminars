#include <iostream>

constexpr int add(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x + y;
}

int main() {

	int input = 0;
	std::cin >> input;

	int x1 = add(1, 2);
	int x2 = add(1, input);
	
	constexpr int y1 = sub(1, 2);
	constexpr int y2 = sub(1, input);
	
	constexpr int z1 = add(1, 2);
	constexpr int z2 = add(1, input);

}

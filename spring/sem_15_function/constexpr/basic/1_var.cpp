#include <iostream>


int main() {


	constexpr int z = 27;

	int x_in = 0;
	std::cin >> x_in;
	const int y = x_in;
	constexpr int w = x_in;
}

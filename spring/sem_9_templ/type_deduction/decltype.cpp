
#include <iostream>

int main() {

	int x = 0;
	int& y = x;
	// decltype(y) z = 42;
	decltype(x) w = 27;

	decltype(++x) ww = x;

	auto one = x;
	++one;
	
	auto two = y;
	++two;

	decltype(auto) three = x;
	++three;
	
	decltype(auto) four = y;
	++four;

	std::cout << x << '\n';

	decltype((x)) five = y;
	++five;
	std::cout << y << '\n';
}

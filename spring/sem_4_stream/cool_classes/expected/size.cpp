#include <iostream>
#include <expected>
#include <array>


int main() {
	std::expected<double, int> value;
	std::cout << "sizeof(std::expected<double, int>) = " << sizeof(value) << '\n';
	std::cout << "sizeof(std::expected<std::array<char, 7>, int>) = " << sizeof(std::expected<std::array<char, 7>, int>) << '\n';

}

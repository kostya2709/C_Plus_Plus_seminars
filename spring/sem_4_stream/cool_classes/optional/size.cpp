#include <iostream>
#include <optional>
#include <array>


int main() {
	std::optional<double> value;
	std::cout << "sizeof(std::optional<double>) = " << sizeof(value) << '\n';

	value = 5;
	std::cout << "sizeof(std::optional<double>) = " << sizeof(value) << '\n';

	std::cout << "sizeof(std::optional<std::array<char, 7>>) = " << sizeof(std::optional<std::array<char, 7>>) << '\n';

}

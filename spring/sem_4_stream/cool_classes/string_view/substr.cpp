#include <iostream>
#include <string>

int main() {

	std::string str = "abcdefgh";
	std::string_view sv(str);

	std::string_view substr = sv.substr(2, 4);
	std::cout << substr << '\n';
}

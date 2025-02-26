#include <string>
#include <optional>
#include <iostream>

std::optional<int> parse_int(const std::string& s) {
    try {
        return std::stoi(s);
    } catch (...) {
        return std::nullopt;
    }
}

int main() {
	auto result = parse_int("42");
	if (result) {
		std::cout << *result << '\n';
	} else {
		std::cout << "Invalid input\n";
	}
}

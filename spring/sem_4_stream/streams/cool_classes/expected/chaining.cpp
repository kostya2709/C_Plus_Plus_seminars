#include <iostream>
#include <expected>
#include <string>

std::expected<int, std::string> parse(std::string_view input) {
    if (input.empty()) return std::unexpected("Empty input");
    return 100;
}

std::expected<int, std::string> process(int value) {
    if (value > 0) return value * 2;
    return std::unexpected("Invalid value");
}

std::expected<int, std::string> plus_10(int x) {
	return x + 10;
}

int main() {
	auto result = parse("input")
		.and_then(process)
		.and_then(plus_10);
	if (result.has_value()) {
		std::cout << result.value() << '\n';
	} else {
		std::cout << "ERROR! " << result.error() << '\n';
	}
}

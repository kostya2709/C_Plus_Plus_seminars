#include <expected>
#include <string>
#include <iostream>

std::expected<int, std::string> compute_value(bool success) {
    if (success) {
        return 42;
    } else {
        return std::unexpected("Calculation failed");
    }
}

int main() {

	auto result = compute_value(true);

	if (result) {
		std::cout << "Value: " << *result << "\n";
	} else {
		std::cout << "Error: " << result.error() << "\n";
	}

}

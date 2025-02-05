#include <cmath>
#include <expected>
#include <iostream>
#include <utility>

enum class Error {
    invalid_value,
    zero
};

[[nodiscard]] std::expected<double, Error> divide(double x, double y) {
    if (std::abs(y) < 1e-7) {
        return std::unexpected(Error::zero);
    }
    return x / y;
}

int main() {
    double x = 10;
    double y = 0;
    
    // divide(x, y);
    
    if (const auto value = divide(x, y); value.has_value()) {
        std::cout << "Norm value: " << *value << "\n";
    } else if (value.error() == Error::zero) {
        std::cout << "Division by zero\n";
    } else {
        std::unreachable();
    }
}
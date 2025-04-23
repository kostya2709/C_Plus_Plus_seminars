#include <iostream>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_integral_v<T>, void> foo(T) {
    std::cout << "Integer overload\n";
}

template <typename T>
std::enable_if_t<std::is_floating_point_v<T>, void> foo(T) {
    std::cout << "Floating-point overload\n";
}

int main() {
    foo(42);
    foo(3.14);
    // foo("hello");
}

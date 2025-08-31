#include <type_traits>
#include <iostream>

template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
void foo(T x) {
	std::cout << "1\n";
}

template <typename T, std::enable_if_t<!std::is_integral_v<T>, bool> = true>
void foo(T x) {
	std::cout << "2\n";
}


int main() {

	foo(1);
	foo(1.0);

}



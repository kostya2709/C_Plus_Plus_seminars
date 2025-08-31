#include <iostream>
#include <type_traits>

template <typename T, typename U>
struct is_same {
	static constexpr bool value = false;
};

template <typename T>
struct is_same<T, T> {
	static constexpr bool value = true;
};

template <typename T, typename U>
constexpr bool is_same_v = is_same<T, U>::value;

template <typename T, typename U>
void foo() {
	if constexpr (is_same<T, U>::value) {
//	if constexpr (std::is_same<T, U>::value) {
//	if constexpr (is_same<T, U>::value) {
//	if constexpr (std::is_same_v<T, U>) {
		std::cout << "Same\n";
	} else {
		std::cout << "Not same\n";
	}
}

int main() {
	foo<int, double>();
	foo<int, int>();
}

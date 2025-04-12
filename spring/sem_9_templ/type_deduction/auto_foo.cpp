#include <utility>

template <typename T>
void check_type() = delete;

template <typename T>
auto foo(T x) {
	return 10;
}

template <typename T>
auto foo1(T x) {
	if (x > 0) {
		return 10;
	} else {
		return 1.0;
	}
}

template <typename T>
auto foo2(T x) {
	if constexpr (std::is_same_v<int, T>) {
		return 1.0;
	} else {
		return 10;
	}
}

template <typename T>
auto bar(T x) -> double {
	return 10;
}
	
auto baz(auto x) {
	return 10;
}

int main() {
	auto x = foo(1);
	double y = bar(1);
	char z = baz('0');
	double w = baz(0.0);
}

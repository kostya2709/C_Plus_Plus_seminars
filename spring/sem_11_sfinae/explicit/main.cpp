#include <type_traits>

template <typename T>
struct Test {
	explicit (!std::is_integral_v<T>) Test(int x) {}
};

Test<int> build_test_int() {
	return 1;
}

Test<float> build_test_float() {
	return 1.0;
}


int main() {

	auto test1 = build_test_int();
	auto test2 = build_test_float();
}

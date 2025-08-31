#include <iostream>
#include <span>


int main() {
	constexpr int a[]{0, 1, 2, 3, 4, 5, 6, 7, 8};
	constexpr std::span<int, 4> test_span = std::span{a, 4};
	static_assert(test_span.size() == 4);
}

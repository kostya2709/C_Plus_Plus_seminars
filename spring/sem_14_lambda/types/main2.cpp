#include <type_traits>
#include <utility>

auto generator() {
	return [](int x, int y) { return x < y; };
}

int main() {

	auto cmp1 = generator();
	auto cmp2 = generator();

	cmp1 = cmp2;
	static_assert(std::is_same_v<decltype(cmp1), decltype(cmp2)>);

	return cmp1(1, 2) < cmp2(3, 4); // just not to let a compiler to optimize
}

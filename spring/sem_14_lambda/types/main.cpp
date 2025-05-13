#include <type_traits>

int main() {

	auto cmp1 = [](int x, int y){ return x < y; };
	auto cmp2 = [](int x, int y){ return x < y; };

//	cmp1 = cmp2;
// 	static_assert(std::is_same_v<decltype(cmp1), decltype(cmp2)>);

	return cmp1(1, 2) < cmp2(3, 4); // just not to let a compiler to optimize
}

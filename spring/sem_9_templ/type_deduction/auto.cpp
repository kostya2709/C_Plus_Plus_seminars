#include <utility>

template <typename T>
void check_type() = delete;

template <typename T>
void foo(T x) {

}

int main() {

	auto x = 10;
	check_type<decltype(x)>();

	auto& y = x;
	check_type<decltype(y)>();

	auto&& z = std::move(y);
	check_type<decltype(z)>();
	
	auto&& u = y;
	check_type<decltype(u)>();
}

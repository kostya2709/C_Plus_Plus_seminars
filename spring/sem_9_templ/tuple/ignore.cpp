#include <iostream>

struct Base {
	void foo(int x) {
		std::cout << "Base::foo(): " << x << '\n';
	}
};

struct Derived : Base {
	void foo(int x) {
		std::ignore = x;
		std::cout << "Derived::foo(): " << '\n';
	}
};

[[nodiscard]] int noDiscardFoo() {
	return 42;
}


int main() {

	Base b;
	Derived d;

	b.foo(42);
	d.foo(27);

	std::pair pair{1, 2};
	[[maybe_unused]] int one, two;
	std::tie(std::ignore, two) = pair;

	std::ignore = noDiscardFoo();

	auto [_, _] = pair;
}

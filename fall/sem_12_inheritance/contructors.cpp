#include <iostream>

struct Base {

	Base(int x = 0) : base_x(x) {
		std::cout << "Base::Base: " << x << '\n';
	}

	int base_x;
};


struct Derived : Base {
	Derived(int x) : Base(x + 1), derived_x(x) {
//	Derived(int x) : base_x(0), derived_x(x) {
		std::cout << "Derived::Derived: " << x << '\n';
	}

	int derived_x;
};

int main() {
	Derived d(0);
}

#include <iostream>

struct Base {
	void foo() {
		std::cout << "Base::foo()\n";
	}
};

struct Derived : Base {
	void foo() {
		std::cout << "Derived::foo()\n";
	}
};

int main() {
	Derived d;
	d.foo();
}

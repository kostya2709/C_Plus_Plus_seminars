#include <iostream>

struct Base {

	virtual static void foo() {
		std::cout << "Base::foo()\n";
	}
	
	static void bar() {
		std::cout << "Base::bar()\n";
	}
};

struct Derived: Base {
	static void foo() {
		std::cout << "Derived::foo()\n";
	}
	
	static void bar() {
		std::cout << "Derived::bar()\n";
	}
};

int main() {
	Base::foo();

	Derived d;
	Base* b_ptr = &d;

	b_ptr->foo();
	b_ptr->bar();

}

#include <iostream>

struct Base {

	virtual void foo() = 0;
	
	void bar() {
		std::cout << "Base::bar()\n";
	}
};

struct Derived: Base {
	void foo() {
		std::cout << "Derived::foo()\n";
	}
	
	void bar() {
		std::cout << "Derived::bar()\n";
	}
};

int main() {

	Derived d;
	Base* b_ptr = &d;

	b_ptr->foo();
	b_ptr->bar();

	// Base b;

}

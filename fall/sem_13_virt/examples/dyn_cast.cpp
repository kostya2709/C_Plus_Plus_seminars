#include <iostream>

struct Base {

	virtual void foo() {
		std::cout << "Base::foo()\n";
	}
};

struct Derived: Base {
	void foo() {
		std::cout << "Derived::foo()\n";
	}
};

struct Descendant: Base {
	void foo() {
		std::cout << "Descendant::foo()\n";
	}
};

int main() {

	Derived d;
	Base* b_ptr = &d;

	Derived& d_new = dynamic_cast<Derived&>(*b_ptr);
	d_new.foo();
	
	Descendant* d_new2 = dynamic_cast<Descendant*>(b_ptr);
	if (d_new2) {
		d_new2->foo();
	} else {
		std::cout << "Not Descendant :(\n";
	}
}

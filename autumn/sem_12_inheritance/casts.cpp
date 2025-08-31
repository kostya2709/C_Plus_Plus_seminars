#include <iostream>

struct Base {
	int base_x = 0;
	Base() = default;
	Base(const Base& other) { std::cout << "Base(const Base&)\n"; }
};


struct Derived : public Base {
	int derived_x = 0;

};


void foo(Base& b) {
	std::cout << "foo(Base&): " << b.base_x << '\n';
}


void bar(Base b) {
	std::cout << "foo(Base): " << b.base_x << '\n';
}


int main() {

	Derived d;
	foo(d);
	bar(d);

	Base true_base;
	Base* b = &true_base;

	int x = 0;
	Derived* dptr = static_cast<Derived*>(b);
	dptr->derived_x = 0;
/*
	Base* b_ptr = &d;
	Base b;
	Derived* d2 = static_cast<Derived*>(&b);
	d2->derived_x = 19;
*/
}

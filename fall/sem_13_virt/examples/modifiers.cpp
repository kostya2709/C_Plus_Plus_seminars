#include <iostream>

struct Base {

	virtual void foo() /*const*/ {
		std::cout << "Base::foo()\n";
	}
	
	void bar() {
		std::cout << "Base::bar()\n";
	}
};

struct Derived: Base {
	void foo() {
		std::cout << "Derived::foo()\n";
	}
	
	virtual void bar() {
		std::cout << "Derived::bar()\n";
	}
};

struct Descendant: Derived {
	void foo() {
		std::cout << "Descendant::foo()\n";
	}
	
	void bar() {
		std::cout << "Descendant::bar()\n";
	}
};
int main() {

	Descendant d;
	Base* b_ptr = &d;
	Derived* d_ptr = &d;

	b_ptr->foo();
	b_ptr->bar();

	d_ptr->foo();
	d_ptr->bar();


}

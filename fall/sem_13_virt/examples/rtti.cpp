#include <iostream>
#include <typeindex>

struct Base {

	virtual void foo() {
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
	
	void bar() {
		std::cout << "Derived::bar()\n";
	}
};

int main() {

	Derived d;
	Base* b_ptr = &d;

	b_ptr->foo();
	b_ptr->bar();


	const std::type_info& info = typeid(*b_ptr);
	std::cout << "Name: " << info.name() << '\n';


}

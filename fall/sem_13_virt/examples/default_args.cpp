#include <iostream>

struct Base {
    virtual void foo(int x = 1) {
		std::cout << "Base::f(): " << x << '\n';
	}
};

struct Derived: Base {
    void foo(int x = 2) { 
		std::cout << "Derived::foo(): " << x << '\n';
	}
};

int main() {
    Derived d;
    Base& b = d;
    b.foo();
}

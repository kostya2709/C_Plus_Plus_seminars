#include <iostream>
#include <stdio.h>

class Base {
public:
    virtual void foo() {
        std::cout << "Base::foo(): " << base_field << "\n";
    }
    void base_foo_not_virtual() {
        std::cout << "Base::base_foo_not_virtual()\n";
    }
	virtual void base_not_overriden() {
		std::cout << "Base::base_not_overriden()\n";
	}
    int base_field;
};

class Derived : public Base {
public:
    void foo() override {
        std::cout << "Derived::foo(): " << base_field << "\n";
    }
    void derived_foo_not_virtual() {
        std::cout << "Derived::derived_foo_not_virtual()\n";   
    }
    int derived_field;
};

int main() {

    Base b1;
    Derived d1;
    
    Base* imposter = &d1;

    b1.base_field = 10;
    d1.base_field = 20;

    b1.foo();
    d1.foo();
    
	imposter->foo();
    // imposter->derived_foo_not_virtual();
	imposter->base_foo_not_virtual();

    std::cout << "Sizeof(Base) == " << sizeof(b1) << std::endl;
    std::cout << "Sizeof(Derived) == " << sizeof(d1) << std::endl;

    return 0;
}

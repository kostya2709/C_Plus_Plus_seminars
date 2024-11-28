#include <iostream>

class Base {
public:
    Base(int x) : base_int(x) { std::cout << "Base(int x)\n"; }
	Base(const Base& other) : base_int(other.base_int) { std::cout << "Base(const Base&)\n"; }
	
	int base_int;
};

class Derived : public Base {
public:
	int derived_int = 0;
	using Base::Base; // Наследуем конструкторы из Base
};

int main() {
    Derived d1(10);      // Вызывает Base(int x)
	d1.derived_int = 42;
	std::cout << d1.derived_int << '\n';

	Derived d2(d1);
	std::cout << d2.derived_int << '\n';
	
	// Derived d3(Base(0));
	return 0;
}

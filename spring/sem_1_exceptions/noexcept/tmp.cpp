#include <iostream>

struct Base {};

struct Derived : Base {};

int main() {
try {
	Derived d;	
	Base& b = d;
	throw b;
} catch (Derived d) {
	std::cout << "D";
} catch (Base b) {
	std::cout << "B";
}
}

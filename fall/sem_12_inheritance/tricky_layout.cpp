#include <iostream>
#include <iostream>

struct Base {
private:  // public / private ?
	double d;
	int x;
};

struct Derived : public Base {
	int y;
};

int main() {
	std::cout << "sizeof(Base) = " << sizeof(Base) << '\n';
	std::cout << "sizeof(Derived) = " << sizeof(Derived) << '\n';
}

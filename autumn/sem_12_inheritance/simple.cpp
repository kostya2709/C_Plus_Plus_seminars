#include <iostream>

class Base {
public:
	int public_x = 0;
protected:
	int protected_x = 0;
private:
	int private_x = 0;
};

class Derived : public Base {
	void foo() {
		int x = public_x;
		int y = protected_x;
		int z = private_x;
	}
};

int main() {

	Base b;
	Derived d;

	d.public_x;
	d.protected_x;
	d.private_x;

}

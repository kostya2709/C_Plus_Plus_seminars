#include <iostream>

class Base {
public:
	virtual void foo() {

	}

	~Base() {
		std::cout << "Base::~Base\n";
	}
};

class Derived : public Base {
public:
	Derived() : data(new int(27)) {
	}

	~Derived() {
		std::cout << "Derived::~Derived\n";
		delete data;
	}
private:
	int* data = nullptr;
};

int main() {
	Base* b_ptr = new Derived();
	delete b_ptr;
}

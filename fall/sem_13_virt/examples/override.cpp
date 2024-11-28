#include <iostream>


struct Base {
	virtual void override() {
		std::cout << "Base::override()\n";
	}
};

struct Derived: Base {
	void override() override {
		int override = 0;
		double final = 0;
		std::cout << "Derived::override()\n";
	}
};

int main() {

	Derived d;
	Base* b_ptr = &d;

	b_ptr->override();

}

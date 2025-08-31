#include <iostream>
#include <vector>

struct Base {
	virtual void foo() = 0;
	~Base() = default;
};

void Base::foo() {
	std::cout << "Base::foo()\n";
}

struct Derived: Base {
	void foo() override {
		std::cout << "Derived::foo()\n";
	}
};

struct Descendant: Base {
	void foo() override {
		std::cout << "Descendant::foo()\n";
	}
};

int main() {

	Derived d;
	Base* b_ptr = &d;
	b_ptr->Base::foo();
	b_ptr->foo();

	Descendant d2;
	Base* b_ptr2 = &d2;
	b_ptr2->foo();

	std::vector<Base*> bases;
	bases.push_back(b_ptr);
	bases.push_back(b_ptr2);	

	std::cout << "\n\nBases:\n";
	for (Base* base : bases) {
		base->foo();
	}

}

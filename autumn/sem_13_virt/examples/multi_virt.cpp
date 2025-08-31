#include <iostream>

struct Mom {
	virtual void foo() {
		std::cout << "Mom::foo()\n";
	}
};

struct Dad {
	void foo() {
		std::cout << "Dad::foo()\n";
	}
};

struct Son: Mom, Dad {
	void foo() override {
		std::cout << "Son::foo()\n";
	}
};

int main() {

	Son son;
	Mom& mom = son;
	Dad& dad = son;

	mom.foo();
	dad.foo();

}

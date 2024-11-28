#include <iostream>

struct Mom {
	virtual void foo() {
		std::cout << "Mom::foo()\n";
	}
	int mom_field = 0;
};

struct Dad {
	virtual void foo() {
		std::cout << "Dad::foo()\n";
	}
	int dad_field = 1;
};

struct Son : Mom, Dad {
	virtual void foo() {
		std::cout << "Son::foo()\n";
	}
	int son_field = 2;
};

int main() {

	Son son;
	Mom* mom = &son;
	
//	Dad* dad = mom;
//	Dad* dad = static_cast<Dad*>(mom);
//	Dad* dad = reinterpret_cast<Dad*>(mom);
//	Dad* dad = &son;
//	Dad* dad = dynamic_cast<Dad*>(mom);

	dad->foo();
	std::cout << dad->dad_field << '\n';

}

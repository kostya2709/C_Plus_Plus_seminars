#include <iostream>

struct Granny {
	virtual void foo() {

	}
	int granny_int = 0;
};

struct Mom : virtual Granny {
	void foo() {

	}
	int mom_int = 1;
};

struct Dad : virtual Granny {
	void foo() {

	}
	int dad_int = 2;
};

struct Son : Mom, Dad {

	void foo() {

	}

	int son_int = 3;
};

int main() {
	Son son;
	Granny& granny = son;

//	Son& son2 = granny;
//	Son& son2 = static_cast<Son&>(granny);
//	Son& son2 = reinterpret_cast<Son&>(granny);
//	Son& son2 = dynamic_cast<Son&>(granny);

	std::cout << son2.son_int << '\n';

}

#include <iostream>
#include <iostream>

struct Granny {
	int granny_x = 0;
	Granny(int x): granny_x(x) {
		std::cout << "Granny " << x << '\n';	
	}
	Granny() = default;
};

struct Mom : virtual Granny {
	int mom_x = 0;
	Mom(): Granny(0) {
		mom_x = granny_x;
	}
};

struct Dad : virtual Granny {
	int dad_x = 0;
	Dad(): Granny(1) {
		dad_x = granny_x;
	}
};

struct Son : Mom, Dad {
	int son_x = 0;
	Son(): Mom(), Dad() {

	}
};


int main() {
	Son son;
	std::cout << son.granny_x << son.mom_x  << '\n';
	std::cout << son.son_x << son.dad_x << son.mom_x << son.granny_x << '\n';

	// std::cout << son.son_x << son.dad_x << son.mom_x << son.Mom::granny_x << '\n';
}

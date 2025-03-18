#include <iostream>

class Test {
public:
	Test() = default;
	Test(const Test& other) {
		std::cout << "const Test& other\n";
	}
};

int main() {

	try {
		Test test;
		throw test;
	} catch (const Test& exc) {
		std::cout << "Caught\n";
	}

}


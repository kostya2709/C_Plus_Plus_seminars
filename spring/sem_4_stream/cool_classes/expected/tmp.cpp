
#include <iostream>

class Printer {
	public:
	Printer(int) {
		std::cout << "Printer()\n";
	}
};

class Test {
	public:
	int x;
	static Printer field;

};

// Printer Test::field(0);

int main() {

	Test t;
	Printer p = Test::field;

}



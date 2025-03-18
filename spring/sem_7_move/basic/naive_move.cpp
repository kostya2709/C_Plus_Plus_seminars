#include <iostream>

struct Test {
	Test() {
		std::cout << "Test()\n";
	}
	Test(const Test& other) {
		std::cout << "Test(const Test&)\n";
	}
	Test(Test&& other) {
		std::cout << "Test(Test&&)\n";
	}
	Test& operator=(const Test& other) {
		std::cout << "operator=(const Test&)\n";
		return *this;
	}
	Test& operator=(Test&& other) {
		std::cout << "operator=(Test&&)\n";
		return *this;
	}
};

template <typename T>
T&& move(T& x) {
	return static_cast<T&&>(x);
}

int main() {
	Test test1;
	std::cout << "---\n";
	
	Test test2(move(test1));
	std::cout << "---\n";
	
	test1 = move(test2);
}

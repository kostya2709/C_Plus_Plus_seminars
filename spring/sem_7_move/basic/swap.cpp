#include <iostream>

class Test {
public:
	Test() = default;
	Test(const Test& other) {
		std::cout << "Test(const Test& other)\n";
	}
	Test(Test&& other) {
		std::cout << "Test(Test&& other)\n";
	}
	Test& operator=(const Test& other) {
		std::cout << "operator=(const Test& other)\n";
		return *this;
	}
	Test& operator=(Test&& other) {
		std::cout << "operator=(Test&& other)\n";
		return *this;
	}
};

template <typename T>
void swap(T& left, T& right) {
	T tmp = std::move(left);
	left = std::move(right);
	right = std::move(tmp);
}

int main() {
	Test a, b;
	swap(a, b);
}


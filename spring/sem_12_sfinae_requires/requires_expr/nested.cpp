#include <iostream>

template <typename T>
requires requires (T) {
	requires (sizeof(T) == 27);
}
void foo() {
	std::cout << "Ok\n";
}

int main() {

	foo<int>();

}

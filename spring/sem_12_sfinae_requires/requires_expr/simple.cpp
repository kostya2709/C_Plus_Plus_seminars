#include <iostream>

template <typename T>
requires requires (T) {
	sizeof(T) == 27;
}
void foo() {
	std::cout << "Ok\n";
}

int main() {

	foo<int>();

}

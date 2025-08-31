#include <iostream>
#include <vector>

template <typename T>
requires requires {
	typename T::value_type;
}
void foo() {
	std::cout << "Ok\n";
}

int main() {

	foo<std::vector<int>>();
//	foo<int>();

}

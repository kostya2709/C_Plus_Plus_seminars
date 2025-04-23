#include <iostream>
#include <vector>

void foo(...) {
	std::cout << "1\n";
}


template <typename T>
auto foo(T x, typename T::value_type = 0) {
	std::cout << "2\n";
	return 0;
}


int main() {

	foo(0);
	
	std::vector<int> vec;
	foo(vec);

}

#include <iostream>
#include <vector>

void foo(...) {
	std::cout << "1\n";
}


template <typename T, typename T::value_type = 0>
auto foo(T x) {
	std::cout << "2\n";
	return 0;
}


int main() {

	foo(0);
	
	std::vector<int> vec;
	foo(vec);

}

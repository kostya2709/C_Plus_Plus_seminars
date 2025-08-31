#include <array>
#include <iostream>

template <typename N, typename M>
class Matrix {

};


template <typename T, size_t N>
class Array {
	T data[N] = {};
};

int foo() {
	return 0;
}

int main() {

	std::array<int, 10> arr;
	

	const int x = 0; // foo();
	Array<int, x> arr2;

}

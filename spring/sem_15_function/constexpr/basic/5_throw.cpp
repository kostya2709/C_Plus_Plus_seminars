#include <iostream>

constexpr int sum(int x) {
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int* arr_end = arr + 10;
	int sum = 0;
	for (int* ptr = arr; ptr != arr_end; ++ptr) {
		sum += *ptr;
	}

	if (x) {
		throw 1;
	}

	return sum + x;
}


int main() {

	static_assert(sum(0) == 45);
	static_assert(sum(42) == 45);
}

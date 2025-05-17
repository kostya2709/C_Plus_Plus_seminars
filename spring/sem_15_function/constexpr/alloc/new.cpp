#include <numeric>

constexpr int foo(int n) {
	int* ptr = new int[n];
	std::iota(ptr, ptr + n, 1);

	int sum = 0;
	for (int i = 0; i <= n; ++i) {
		sum += i;
	}

	delete[] ptr;
	// delete[] ptr;
	return sum;
}


int main() {
	static_assert(foo(3) == 6);
}

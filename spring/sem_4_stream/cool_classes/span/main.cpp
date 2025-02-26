#include <iostream>
#include <vector>
#include <array>
#include <span>

void bad_process(int* data, size_t size) {
    for (size_t i = 0; i < size; ++i) {
    // What if we get out of the range?
	}
}

void process(std::span<int> data) {
    for (auto& val : data) {
        // Safe
		std::cout << val << ' ';
    }
	std::cout << '\n';
}

int main() {

	int arr[] = {1, 2, 3, 4};
	std::vector<int> vec = {5, 6, 7};
	std::array<int, 3> std_arr = {8, 9, 10};

	process(arr);
	process(vec);
	process(std_arr);

}

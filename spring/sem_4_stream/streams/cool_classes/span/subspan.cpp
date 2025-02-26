#include <iostream>
#include <vector>
#include <array>
#include <span>


int main() {
	std::vector<int> data = {0, 1, 2, 3, 4, 5};
	std::span<int> full_view{data};

	std::span<int> sub_view = full_view.subspan(2, 3);
	sub_view[0] = 99;

	std::cout << "Sub_view: ";
	for (auto elem : sub_view) {
		std::cout << elem << ' ';
	}
	
	std::cout << "\nSequence:";
	for (auto elem : data) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';

}

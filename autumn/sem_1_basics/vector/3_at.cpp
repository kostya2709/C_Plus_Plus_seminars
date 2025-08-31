#include <string>
#include <vector>
#include <iostream>

int main() {
	std::vector<int> data = {1, 2, 3, 4, 5};
	std::cout << data[42] << "\n";  // UB
	std::cout << data.at(0) << "\n";  // 1
	std::cout << data.at(42) << "\n";  // std::out_of_range exception
}

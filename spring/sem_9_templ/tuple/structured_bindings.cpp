#include <iostream>
#include <map>
#include <array>
#include <vector>

struct Test {
	int x{10};
// private:
	double y{3.1415};
};


int main() {

	auto [x_field, y_field] = Test();
	std::cout << "x: " << x_field << "; y: " << y_field << '\n';

	int array[2] = {1, 2};
	const auto [first, second] = array;
	std::cout << "first: " << first << "; second: " << second << '\n';
	
	std::array<int, 2> array2{3, 4};
	const auto [first_2, second_2] = array;
	std::cout << "first: " << first_2 << "; second: " << second_2 << '\n';

	std::cout << "Map:\n";
	std::map<int, int> map{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
	for (const auto& [key, value] : map) {
		std::cout << key << ' ' << value << ' ';
	}

	std::cout << "\nPair\n";

	std::pair pair{1, 2.0};
	auto& [int_val, double_val] = pair;
	int_val = 42;
	double_val = 27.0;
	std::cout << pair.first << ' ' << pair.second << '\n';

}

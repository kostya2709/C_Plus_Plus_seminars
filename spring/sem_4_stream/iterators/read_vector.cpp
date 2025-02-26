#include <vector>
#include <iostream>
#include <iterator>
#include <sstream>

int main() {

	std::vector<int> numbers;

	std::copy(
		std::istream_iterator<int>(std::cin),
		std::istream_iterator<int>(),
		std::back_inserter(numbers)
	);

/*
	std::vector<int> numbers2 {
		std::istream_iterator<int>(std::cin),
		std::istream_iterator<int>()
	};
*/

	std::cout << "\nVector numbers:\n";
	for (int elem : numbers2) {
		std::cout << elem << '\n';
	}
	std::cout << '\n';










	std::string input = "Hello World C++";
	std::istringstream iss(input);

	std::vector<std::string> words;
	std::copy(
		std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>(),
		std::back_inserter(words)
	);

	std::cout << "\nVector words:\n";
	for (const auto& elem : words) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}

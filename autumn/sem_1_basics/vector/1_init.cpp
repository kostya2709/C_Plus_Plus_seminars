#include <iostream>
#include <vector>

int main() {

    std::vector<int> data = {1, 2, 3, 4, 5}; // initializer list
    std::vector<std::string> v1;  // empty vector of strings
    std::vector<std::string> v2(5);  // vector of 5 empty strings
    std::vector<std::string> v3(5, "hello");  // vector of 5 "hello" strings

    for (int elem : data) {
        std::cout << elem << " ";
	}

    std::cout << '\n';

	for (std::string elem : v3) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';

}

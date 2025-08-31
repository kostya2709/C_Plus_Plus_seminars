#include <string>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> data = {1, 2, 3, 4, 5};
	int a = data[0];
	int b = data[4];
	data[2] = -3;

	std::cout << data.size() << '\n';
}

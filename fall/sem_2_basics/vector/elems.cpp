#include <string>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> data = {1, 2, 3, 4, 5};
	int a = data[0];  // начальный элемент вектора
	int b = data[4];  // последний элемент вектора (в нём пять элементов)
	data[2] = -3;  // меняем элемент 3 на -3

	std::cout << data.size() << '\n';
}

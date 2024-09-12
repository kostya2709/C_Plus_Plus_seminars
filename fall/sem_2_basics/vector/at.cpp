#include <string>
#include <vector>
#include <iostream>

int main() {
	std::vector<int> data = {1, 2, 3, 4, 5};
	std::cout << data[42] << "\n";  // неопределённое поведение: может произойти всё что угодно
	std::cout << data.at(0) << "\n";  // напечатается 1
	std::cout << data.at(42) << "\n";  // произойдёт исключение std::out_of_range — его можно будет перехватить и обработать
}

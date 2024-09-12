#include <iostream>
#include <vector>

int main() {

    std::vector<int> data = {1, 2, 3, 4, 5}; // список инициализации
    std::vector<std::string> v1;  // пустой вектор строк
    std::vector<std::string> v2(5);  // вектор из пяти пустых строк
    std::vector<std::string> v3(5, "hello");  // вектор из пяти строк "hello"

    for (int elem : data) {
        std::cout << elem << " ";
    }
    std::cout << '\n';

	for (std::string elem : v3) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';

}

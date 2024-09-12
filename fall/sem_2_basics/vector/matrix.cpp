#include <iostream>
#include <vector>

int main() {
    size_t lines = 0, cols = 0;
    std::cin >> lines >> cols;

    std::vector<std::vector<int>> matrix(lines, std::vector<int>(cols));

    for (size_t i = 0; i != lines; ++i) {
        for (size_t j = 0; j != cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (size_t i = 0; i != lines; ++i) {
        for (size_t j = 0; j != cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

int main() {
    std::ifstream file("fstream.cpp");
    if (file.is_open()) {
        std::istream_iterator<std::string> fileIterator(file);
        std::istream_iterator<std::string> endIterator;
        while (fileIterator != endIterator) {
            std::cout << *fileIterator << std::endl;
            ++fileIterator;
        }
    }
    file.close();
}

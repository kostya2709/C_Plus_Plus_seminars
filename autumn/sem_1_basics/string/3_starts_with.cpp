#include <iostream>
#include <string>

int main() {
    std::string data;
    std::getline(std::cin, data);

    if (data.starts_with("hello")) {
        std::cout << "Hi!\n";
    }

    if (data.ends_with("bye")) {
        std::cout << "Good Bye!\n";
    }
}

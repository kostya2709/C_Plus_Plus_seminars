#include <iostream>
#include <string>

int main() {
    std::string s = "Some string functions";

    // вставка подстроки
    s.insert(5, "std::");
    std::cout << s << "\n";  // Some std::string functions

    // замена указанного диапазона на новую подстроку
    s.replace(0, 4, "Special");
    std::cout << s << "\n";  // Special std::string functions

    // удаление подстроки
    s.erase(8, 5);  // Special string functions
}

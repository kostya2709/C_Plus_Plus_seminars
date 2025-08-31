#include <iostream>
#include <string>

int main() {
    std::string s = "Some string";

    s += ' ';
    s += "functions";
    std::cout << s << "\n";

    std::string sub1 = s.substr(5, 6); // string
    std::string sub2 = s.substr(12); // functions

    size_t pos1 = s.find(' ');  // 4
    size_t pos2 = s.find(' ', pos1 + 1);  // 11
    size_t pos3 = s.find("str");  // 5
    size_t pos4 = s.find("#");  // std::string::npos

}

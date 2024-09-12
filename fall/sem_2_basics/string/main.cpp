#include <iostream>
#include <string>

int main() {
    std::string s = "Some string";

    s += ' ';
    s += "functions";
    std::cout << s << "\n";

    // выделение подстроки
    // подстрока "string" из 6 символов начиная с 5-й позиции
    std::string sub1 = s.substr(5, 6);
    // подстрока "functions" с 12-й позиции и до конца
    std::string sub2 = s.substr(12);

    size_t pos1 = s.find(' ');  // позиция первого пробела, в данном случае 4
    size_t pos2 = s.find(' ', pos1 + 1);  // позиция следующего пробела (11)
    size_t pos3 = s.find("str");  // вернётся 5
    size_t pos4 = s.find("#");  // вернётся std::string::npos

}

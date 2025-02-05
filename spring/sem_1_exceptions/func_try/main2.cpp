#include <iostream>

class Thrower {
public:
    Thrower(int x) {
        throw x;
    }
};

class Test {
public:
    int x;
    Thrower thrower;

    Test() try : x(0), thrower(9) {
        std::cout << "Constructor body\n";
    } catch (int x) {
        std::cout << "Caught int " << x << '\n';
        throw std::logic_error("err");
    }
};

int main() {
    Test test;
}
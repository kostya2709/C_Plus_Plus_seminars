#include <iostream>

class Test {
public:
    Test() {
        std::cout << "Test()\n";
        throw 1;
    }

    ~Test() {
        std::cout << "~Test()\n";
    }
};

void foo() {
    static Test test;
}

int main() {
    try {
        foo();
    } catch (int x) {
        std::cout << "Caught int " << x << '\n'; 
    }

    try {
        foo();
    } catch (int x) {
        std::cout << "Caught int " << x << '\n'; 
    }
}
    
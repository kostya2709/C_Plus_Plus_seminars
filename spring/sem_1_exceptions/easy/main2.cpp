#include <iostream>

void foo() {
    throw 42;
}

class Test {
public:
    Test() {
        std::cout << "Test()\n";
    }
    ~Test() {
        std::cout << "~Test()\n";
    }
};

int main() {
    try {
        Test test;
        foo();
    } catch (int x) { // long ?
        std::cout << "Exception " << x << " was caught!\n";
    }
}

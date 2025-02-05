#include <iostream>

class Test {
public:
    Test() {
        std::cout << "Test()\n";
    }

    ~Test() noexcept(false) {
        throw 1;
        std::cout << "~Test()\n";
    }
};

int main() {
    Test* test_ptr = new Test();
    try {
        delete test_ptr;
    } catch (int exc) {
        std::cout << "Caught int " << exc << '\n';
    }
}
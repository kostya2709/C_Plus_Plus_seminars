#include <iostream>

class Test {
public:
    Test() {
        std::cout << "Default constructed\n";
    }

    Test( const Test&) {
        std::cout << "Copy constructed\n";
    }

    ~Test() {
        std::cout << "Destructed\n";
    }
};

int main() {
    try {
		throw Test();
    } catch (Test test) {
       std::cout << "Caught test\n";
       throw test;
    }
}

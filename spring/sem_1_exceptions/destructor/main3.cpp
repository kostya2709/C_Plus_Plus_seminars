#include <iostream>
#include <exception>

void dump_exception_num() {
    std::cout << "Currently have " << std::uncaught_exceptions() << " uncaught exceptions\n";
}

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

void foo() {
    throw 1;
}

class SillyDestr {
public:
    ~SillyDestr() {
        dump_exception_num(); // 3
    }
};

class Test2 {
public:
    Test2() {
        std::cout << "Test2()\n";
    }

    ~Test2() {
        dump_exception_num(); // 2
        std::cout << "~Test2()\n";
        try {
            SillyDestr silly;
            foo();
        } catch (int x) {
            
        }
    }
};

int main() {
    dump_exception_num(); // 1
    Test* test_ptr = new Test();
    try {
        Test2 test2;
        delete test_ptr;
    } catch (int exc) {
        std::cout << "Caught int " << exc << '\n';
    }
}
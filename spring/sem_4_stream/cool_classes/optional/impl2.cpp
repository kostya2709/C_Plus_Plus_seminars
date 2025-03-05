#include <iostream>
#include <tuple>
#include <string>
#include <functional>

struct Test {
    int x = 0;
    Test(int x) {
        std::cout << "TEST " << x << '\n';
    }
    ~Test() {
        std::cout << "~TEST\n";
    }
};

struct Optional {
    union {
        Test test;
    };
    bool has_value = false;

    Optional() {}
    ~Optional() {
        if (has_value) {
            test.~Test();
        }
    }
    Optional& operator=(int x) {
        has_value = true;
        new (&test) Test(x);
        return *this;
    }
};

int main() {
    Optional opt;
    std::cout << "empty\n";
    opt = 15;
}

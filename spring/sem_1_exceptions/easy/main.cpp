#include <iostream>

void foo() {
    throw 42;
}

int main() {
    try {
        foo();
    } catch (int x) {
        std::cout << "Exception " << x << " was caught!\n";
    }
}

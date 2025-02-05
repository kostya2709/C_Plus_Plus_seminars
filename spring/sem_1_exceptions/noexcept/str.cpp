#include <iostream>
#include <signal.h>
#include <string>


void my_handler(int signum) {
    std::cout << "Gotcha!\n";
    exit(3);
}

int main() {
    // signal(SIGSEGV, my_handler);
    std::string str("abc");
    static_assert(!noexcept(str[0]));

    try {
        str[100'000'000] = 0;
    } catch (...) {
        std::cout << "Caught!\n";
    }
}
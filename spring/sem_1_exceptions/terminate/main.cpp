#include <exception>
#include <iostream>
#include <cstdlib>

void new_handler() {
    std::cout << "called a new fancy handler" << std::endl;
    std::abort();
}


int main() {

    // std::terminate();
    //  void (*prev_handler)() = std::set_terminate( new_handler);
    // std::cout << "Calling prev handler...\n";
    // prev_handler();
    // throw 1;
}

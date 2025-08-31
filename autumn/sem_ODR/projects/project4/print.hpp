#include <iostream>

class Printer
{
public:
void print( int x) {
    std::cout << x << '\n';
}
void foo();
};

void Printer::foo() {
    std::cout << "foo\n";
}

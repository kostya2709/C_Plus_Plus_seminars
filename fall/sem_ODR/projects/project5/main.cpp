#include "print.hpp"

void lucky();

static int static_int = 5;
int not_static_int = 10;

static int static_foo( int x)
{
    return 3 * x;
}

class Test {
    public:
    Test( int x) { std::cout << "BUILDING " << x << "\n";}
};

void testing(int x) {
    static Test tmp(x);
}


int main() {

    testing(6);
    testing(7);

    Printer printer;
    printer.print(42);
    printer.outer_method(3);
    lucky();

    int x = Printer::not_const_stat_field;

    static_foo( 5 * static_int + not_static_int);

    return 0;
}

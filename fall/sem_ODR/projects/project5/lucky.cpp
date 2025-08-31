#include "print.hpp"

extern int not_static_int;


void lucky() {
    Printer printer;
    std::cout << "lucky(): not static: " << not_static_int << "\n";
    printer.print(27 + not_static_int);
}

#include <iostream>
#include "print.hpp"

int Printer::not_const_stat_field = 5;

int Printer::outer_method( int x) {
    return 2 * Printer::not_const_stat_field;
}

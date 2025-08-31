#include <iostream>

class Printer
{
public:
    void print( int x) {
        std::cout << "print: " << x << '\n';
    }

    int outer_method( int x);
    
    static int not_const_stat_field;
    
    const static int const_stat_field = 6;
    
    int field = 1;
    const int const_field = 0;
};




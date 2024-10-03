#include <iostream>
#include <iomanip>

int main()
{
    unsigned val = 42;
    std::cout << "Octal: " << std::oct << val << std::endl;
    std::cout << "Decimal: " << std::dec << val << std::endl;
    std::cout << "Hex: " << std::hex << val << std::endl;

    std::cout << "???: " << val << '\n';    
   
    std::cout <<  std::setprecision( 3) << 3.1415926 << std::endl;

    return 0;
}

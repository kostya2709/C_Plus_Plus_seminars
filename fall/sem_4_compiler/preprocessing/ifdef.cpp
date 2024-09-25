#include <iostream>

#ifdef DEBUG
#define HELP() \
    std::cout << "help!\n"
#else
#define HELP()
#endif



int main() {
    
    HELP();

    std::cout << "Finished the program\n";
    return 0;
}

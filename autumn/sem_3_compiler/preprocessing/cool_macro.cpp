#include <iostream>

#define PRINT(smth) std::cout << smth << '\n';

#define ASSERT( cond )                                           \
    if ( !(cond) ) {                                             \
        std::cout << "Codition (" << #cond << ") failed!\n";     \
        std::cout << "Line " << __LINE__ << '\n';                \
        std::cout << "File " << __FILE__ << '\n';                \
        std::cout << "Function " << __PRETTY_FUNCTION__ << '\n'; \
    }

int main() {

    int a = 0;
    int b = 42;    
    
    ASSERT(a == b);

    PRINT( a )
    
    std::cout << "Finished the program\n";
    return 0;
}

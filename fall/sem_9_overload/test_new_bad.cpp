#include "inttypes.h"
#include <cstddef>
#include <new>
#include <vector>
#include <iostream>

int main() {

    const uint64_t SIZE = UINT64_MAX / 4;
    uint8_t* array = new (std::nothrow) uint8_t[SIZE];
    
    // std::vector<int> vec(SIZE);

    if ( array == nullptr )
    {
        std::cout << "Failed to allocate\n";
        return 1;
    }
   
    array[0] = 0;

    delete [] array;

    return 0;
}



// auto vec = std::vector<int>(SIZE);


#include <iostream>

int main()
{
    size_t N = 10;
    int* array = new  int[N];

    std::cout << "Address: " << array << "\n";

    delete[] array;
    
    array[0] = 7;

    return 0;
}

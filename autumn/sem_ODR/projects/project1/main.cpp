#include <iostream>
void print(int);

int main() {
   print(42);

    char* data = new char[100];
    for (int i =0; i < 100; ++i)
    {
        if (data[i])
        {
            std::cout << "FAIL " << i << '\n';
           return 1; 
        }
    }
    
    return 0;

}

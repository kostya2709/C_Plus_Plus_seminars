#include <iostream>

int mul2( int val)
{
    return 2 * val;
}

int pow3( int val)
{
    return val * val * val;
}

int main()
{
    int test_int = 3;
    int( *func_ptr)(int);
    
    func_ptr = mul2;
    std::cout << "mul2: " << "val = " << test_int << " -> " << func_ptr( test_int) << std::endl;
    
    func_ptr = pow3;
    std::cout << "pow3: " << "val = " << test_int << " -> " << func_ptr( test_int) << std::endl;

    return 0;
}

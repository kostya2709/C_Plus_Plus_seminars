#include <iostream>
#include <stdio.h>
 
struct Test {
    // will usually occupy 8 bytes:
    // 5 bits: value of b1
    // 27 bits: unused
    // 6 bits: value of b2
    // 15 bits: value of b3
    // 11 bits: unused
    unsigned b1 : 5;
    unsigned    : 0; // starts a new unsigned int
    unsigned b2 : 6;
    unsigned b3 : 15;
};
 
int main(void) {
	Test obj{3};
	
	std::cout << "obj.b1 = " << obj.b1 << '\n';
	obj.b1 += 29;
	std::cout << "obj.b1 = " <<  obj.b1 << '\n';

	printf("sizeof(Test) = %zu\n", sizeof(obj)); // usually prints 8
}

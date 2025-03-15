#include <new>
#include <iostream>

struct Example {
    int* x;
    Example() {} // x(new int) {}
//	~Example() = default;
//  ~Example() {}
/*
	~Example() {
		std::cout << "~Example\n";
//		delete x;
	}
*/
};

int main() {
//	Example* ptr = new Example;
//	operator delete(ptr);

//	Example* example = reinterpret_cast<Example*>(
//                 new char[sizeof(Example)]);
//    new (example) Example();
    
	Example* example = new Example[1];
    
	example[0].~Example();
    operator delete[](example);
}

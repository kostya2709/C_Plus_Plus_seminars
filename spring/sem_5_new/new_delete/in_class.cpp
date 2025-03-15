#include <iostream>
#include <vector>


void* operator new( size_t n) {
	void* ptr = malloc(n);
	std::cout << "Allocated " << n << " bytes\n";
    return ptr;
}

void operator delete( void* ptr) {
    std::cout << "Deallocating\n";
    free(ptr);
}


void* operator new[]( size_t n) {
	void* ptr = malloc(n);
    std::cout << "Allocated array of " << n << " bytes\n";
    return ptr;
}

void operator delete[]( void* ptr) {
    std::cout << "Deallocated array \n";
    free(ptr);
}


struct Dummy {

    Dummy() noexcept {
        std::cout << "Constructed\n";
    }
    
	~Dummy() noexcept {
        std::cout << "Destructed\n";
    }


    void* operator new( size_t n) {
         std::cout << "Allocated Dummy " << n << " bytes\n";
         return malloc(n);
     }
     
     void operator delete( void* ptr) {
         std::cout << "Deallocated Dummy\n";
         free(ptr);
     }

};

int main() {

    Dummy* obj = new Dummy();
    delete obj;
	std::cout << "\n\n\n";
    
	Dummy* obj2 = ::new Dummy();
    ::delete obj2;
	std::cout << "\n\n\n";

	int* obj_arr = new int[5];
	delete[] obj_arr;
}

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
};

int main() {

    Dummy* obj = new Dummy();
    delete obj;

	int* obj_arr = new int[5];
	delete[] obj_arr;
}

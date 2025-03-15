#include <iostream>
#include <cstdint>


void* operator new( size_t n) {
	void* ptr = malloc(n);
	std::cout << "Allocated " << n << " bytes at " << ptr << '\n';
    return ptr;
}

void operator delete( void* ptr) {
    std::cout << "Deallocating " << ptr << '\n';
    free(ptr);
}


void* operator new[]( size_t n) {
	void* ptr = malloc(n);
    std::cout << "Allocated array " << n << " bytes at " << ptr << '\n';
    return ptr;
}

void operator delete[]( void* ptr) {
    std::cout << "Deallocated array at " << ptr << '\n';
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

void print(uint64_t* ptr) {
	--ptr;	
	std::cout << *ptr << '\n';
}

int main() {

	Dummy* ptr = new Dummy[10];
	std::cout << "Allocation at " << ptr << '\n';

	print(reinterpret_cast<uint64_t*>(ptr));
// size_t num_elem + elem1 + elem2 +...
	delete [] ptr;
}

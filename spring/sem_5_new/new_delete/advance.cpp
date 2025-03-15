#include <iostream>
#include <vector>


void* operator new( size_t n) {
    std::cout << "Allocated " << n << " bytes\n";
    return malloc(n);
}

void operator delete( void* ptr) {
    std::cout << "Deallocated\n";
    free(ptr);
}


void* operator new[]( size_t n) {
    std::cout << "Allocated array " << n << " bytes!\n";
    return malloc(n);
}

void operator delete[]( void* ptr) {
    std::cout << "Deallocated array\n";
    free(ptr);
}


struct Dummy {

    Dummy() {
        std::cout << "Constructed\n";
    }

public:
    // void* operator new( size_t n) {
    //     std::cout << "Allocated Dummy " << n << " bytes\n";
    //     return malloc(n);
    // }
    // 
    // void operator delete( void* ptr) {
    //     std::cout << "Deallocated Dummy\n";
    //     free(ptr);
    // }

};


void* operator new( size_t n, Dummy* ptr) {
    std::cout << "Placement new for Dummy\n";
    return ptr;
}


void* operator new( size_t n, Dummy) {
    std::cout << "Custom new for Dummy\n";
    std::cout << n << "\n";
    return malloc(n);
}

struct nothrow_t {};
nothrow_t nothrow;


void* operator new( size_t n, nothrow_t) {
    return malloc(n);
}

void operator delete( void* ptr, Dummy) {
    std::cout << "Custom operator delete\n";
    free(ptr);
}

int main() {

    // Dummy dummy;
    // Dummy* obj = new(&dummy) Dummy();
    
    // int* arr = new (nothrow) int[100000000];

    // delete obj;

    // Dummy* alpha = reinterpret_cast<Dummy*>(operator new(7));
    // delete alpha;

    // Dummy* beta = reinterpret_cast<Dummy*>(operator new(7));
    // new(beta) Dummy();
    // delete beta;

	new(ptr) T; -> function "operator new" + Constructor
    Dummy dummy;
    Dummy* ptr = operator new(dummy) Dummy();
    // ptr->~Dummy();
    // operator delete(ptr, Dummy());
}

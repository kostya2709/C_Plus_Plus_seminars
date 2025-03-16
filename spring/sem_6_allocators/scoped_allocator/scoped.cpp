#include <iostream>
#include <vector>
#include <scoped_allocator>

template <typename T>
struct MyAllocator {

	using value_type = T;

	MyAllocator() {
		std::cout << "MyAllocator()\n";
	}

	template <typename U>
	MyAllocator(const MyAllocator<U>& other) {
		std::cout << "MyAllocator(other)\n";
	}

    T* allocate(size_t n) {
		std::cout << "Allocating memory for " << n << " objects\n";
		return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* ptr, size_t n) {
		std::cout << "Deallocating memory for " << n << " objects\n";
        ::operator delete(ptr);
    }


    template <typename... Args>
    void construct(T* ptr, const Args&... args) {
		std::cout << "Constructing\n";
        new (ptr) T(args...);
    }

    void destroy(T* ptr) {
		std::cout << "Destroying\n";
        ptr->~T();   
    }
};


template <typename T>
class Alloc {

	template <typename... Args>
	void construct(T* ptr, Args... args) {
		new (ptr) T(args..., *);
	}
};


int main() {

	using InnerVector = std::vector<int, MyAllocator<int>>;
	std::vector<InnerVector, std::scoped_allocator_adaptor<MyAllocator<InnerVector>>> vec(2);
	std::cout << "PushBack\n";
	vec[0].push_back(0);
}

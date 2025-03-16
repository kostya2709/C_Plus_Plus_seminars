#include <iostream>
#include <vector>

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

	MyAllocator select_on_container_copy_construction() const {
		std::cout << "SOCC\n";
		return *this;
	}


    T* allocate(size_t n) {
		std::cout << "Allocating " << n << " objects\n";
		return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* ptr, size_t n) {
		std::cout << "Deallocating " << n << " objects\n";
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

	~MyAllocator() {
		std::cout << "~MyAllocator()\n";
	}
};

template <typename T>
bool operator!=(const MyAllocator<T>& lhs, const MyAllocator<T>& rhs) {
	return false;
}

template <typename T>
bool operator==(const MyAllocator<T>& lhs, const MyAllocator<T>& rhs) {
	return true;
}


int main() {
	std::vector<int, MyAllocator<int>> vec{1, 2, 3};
	std::vector<int, MyAllocator<int>> vec2 = vec;
	
	std::cout << "Copy\n";
	vec = vec2;
	std::cout << "Done copy\n";
}

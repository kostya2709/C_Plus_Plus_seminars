#include <iostream>
#include <vector>



template <typename T>
struct MyAllocator {

	using value_type = T;

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
};


template <typename T, typename Allocator>
class Container {
private:
    //....
    Allocator alloc;
    
   // std::allocator_traits<Alloc>::allocate(alloc, n)

};

template <typename T, typename Alloc = std::allocator<T>>
class List {

    struct Node {
        //...
    };

    typename std::allocator_traits<Alloc>::template rebind_alloc<Node> alloc;

};


int main() {

	std::vector<int, MyAllocator<int>> vec{1, 2, 3};

	for (auto elem : vec) {
		std::cout << elem << '\n';
	}
	
}

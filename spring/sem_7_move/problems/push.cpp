#include <iostream>

void* operator new(size_t n) {
	std::cout << "Allocating " << n << " bytes\n";
	return malloc(n);
}

void operator delete(void* ptr, size_t n) {
	free(ptr);
}

struct Test {
	int* data_ = nullptr;
	Test(int x) : data_(new int(x)) {}
	Test(const Test& other) : data_(new int(*other.data_)) { }
	Test& operator=(const Test& other) {
		*data_ = *other.data_;
		return *this;
	}
	~Test() {
		delete data_;
	}
};

template <typename T>
struct Container {
	alignas(T) std::byte array_[sizeof(T)];
	bool pushed_{false};

	void Push(const T& object) {
		new (array_) T(object);
		pushed_ = true;
	}

	~Container() {
		if (pushed_) {
			reinterpret_cast<T*>(array_)->~T();
		}
	}

};


int main() {
	Container<Test> container;

	Test test(42);
	container.Push(test);
}

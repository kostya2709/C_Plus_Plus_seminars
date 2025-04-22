#include <cassert>
#include <iostream>


template <typename T>
class shared_ptr {
private:
	T* ptr_{nullptr};
	size_t* counter_{nullptr};
public:

	shared_ptr() {}
	shared_ptr(T* ptr) : ptr_(ptr), counter_(new size_t(1)) {}
	
	shared_ptr(const shared_ptr& other) : ptr_(other.ptr_), counter_(other.counter_) {
		if (counter_) {
			++*counter_;
		}
	}

	T& operator*() const {
		return *ptr_;
	}

	~shared_ptr() {
		if (!counter_) {
			return;
		}
		if (--*counter_ == 0) {
			delete ptr_;
			delete counter_;
		}
	}

};


int main() {

	int value = 10;
	int* data = new int(value);

	shared_ptr<int> ptr1(data);
	shared_ptr<int> ptr2(ptr1);

	assert(*ptr1 == value);
	assert(*ptr2 == value);
	
	shared_ptr<int> empty1;
	shared_ptr<int> empty2(empty1);

	std::cout << "All tests passed!\n";

}

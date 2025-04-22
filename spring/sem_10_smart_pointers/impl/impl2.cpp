#include <cassert>
#include <iostream>


// TODO: dispatch have / don't have ControlBlock

template <typename T>
class shared_ptr {
private:
	
	struct ControlBlock {
		T value;
		size_t counter;
	};
	
	template <typename U, typename... Args>
	friend shared_ptr<U> make_shared(Args&&... args);

private:	
	T* ptr_{nullptr};
	size_t* counter_{nullptr};
	ControlBlock* ctrl_ptr_{nullptr};

private:
	
	shared_ptr(ControlBlock* ctrl_ptr) : ctrl_ptr_(ctrl_ptr) {}

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

template <typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args) {
	auto* ptr = new typename shared_ptr<T>::ControlBlock{T(std::forward<Args>(args)...), 1};
	return shared_ptr<T>(ptr);
}

int main() {


	int value = 10;
	
	auto made_shared = make_shared<int>(value);
	assert(*made_shared == value);
	
	int* data = new int(value);

	shared_ptr<int> ptr1(data);
	shared_ptr<int> ptr2(ptr1);

	assert(*ptr1 == value);
	assert(*ptr2 == value);
	
	shared_ptr<int> empty1;
	shared_ptr<int> empty2(empty1);

	std::cout << "All tests passed!\n";

}

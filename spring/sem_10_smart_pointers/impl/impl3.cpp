#include <iostream>

template <typename T>
class shared_ptr {

public:
		
	struct ControlBlock {
		T value;
		size_t count;
	};
	
	shared_ptr(ControlBlock* ctrl_ptr) : ptr_(&ctrl_ptr->value), ctrl_ptr_(ctrl_ptr)  {

	}
	
public:

	shared_ptr() {}
	shared_ptr(T* ptr) : ptr_(ptr), counter_(new size_t(1)) { }

	shared_ptr(const shared_ptr& other) : ptr_(other.ptr_), counter_(other.counter_) {
		if (counter_) {
			++*counter_;
		}
	}


	~shared_ptr() {
		if (counter_ && !--*counter_) {
			delete counter_;
			delete ptr_;
		}
	}

template < typename... Args >
friend shared_ptr<T> make_shared(Args&&... args);

private:
	T* ptr_{nullptr};
	size_t* counter_{nullptr};
	ControlBlock* ctrl_ptr_{nullptr};
};

template <typename T, typename... Args >
shared_ptr<T> make_shared(Args&&... args) {
	return shared_ptr(new typename shared_ptr<T>::ControlBlock{std::forward<Args>(args)..., 1});
}

int main() {
	int* data = new int(42);
	shared_ptr<int> ptr(data);

	shared_ptr<int> ptr2 = ptr;
	shared_ptr<int> ptr3;


	auto ptr4 = make_shared<int>(42);

}

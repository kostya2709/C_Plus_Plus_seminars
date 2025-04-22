#include <cassert>
#include <iostream>


// TODO: dispatch have / don't have ControlBlock

template <typename T>
class shared_ptr {
private:

	
	struct BaseControlBlock {
		size_t shared_counter;
		size_t weak_counter;

		virtual ~BaseControlBlock() = default;
	};

	template <typename Delete, typename Alloc>
	struct ControlBlockPtr : BaseControlBlock {
		Deleter del;
		Alloc alloc;

		ControlBlockPtr(Deleter del, Alloc alloc) : del(del), alloc(alloc) {}
	};

	template <typename U, typename Alloc>
	struct ControlBlockMakeShared : BaseControlBlock {
		U value;
		Alloc alloc;
		
		ControlBlockPtrMakeShared(U value, Alloc alloc) : value(value), alloc(alloc) {}
	};
	
	template <typename U, typename... Args>
	friend shared_ptr<U> make_shared(Args&&... args);

private:	
	T* ptr_{nullptr};
	BaseControlBlock* counter_{nullptr};

private:
	
	shared_ptr(ControlBlock* ctrl_ptr) : ctrl_ptr_(ctrl_ptr) {}

public:

	shared_ptr() {}
	shared_ptr(T* ptr) : ptr_(ptr), counter_(new size_t(1)) {}
	
	shared_ptr(const shared_ptr& other) : ptr_(other.ptr_), counter_(other.counter_) {
		if (counter_) {
			++counter_->shared_counter;
		}
	}

	T& operator*() const {
		return *ptr_;
	}

	~shared_ptr() {
		if (!counter_) {
			return;
		}
		if (--counter_->shared_counter == 0) {

			if (counter_->weak_counter == 0) {
				// ~T + free	
			} else {
				// ~T
			}
			// delete ptr_;
			// delete counter_;
		}
	}

};

template <typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args) {
	auto* ptr = new typename shared_ptr<T>::ControlBlockMakeUnique{T(std::forward<Args>(args)...), /*...*/};
	return shared_ptr<T>(ptr);
}

template <typename T, typename Alloc, typename... Args>
shared_ptr<T> allocate_shared(Alloc alloc, Args&&... args) {
	using CtrlBlockAlloc = typename std::allocator_traits<Alloc>::rebind_alloc<ControlBlockMakeShared<T, Alloc>>;
	CtrlBlockAlloc block_alloc = alloc;
	auto* ptr = block_alloc.allocate(1);
	std::allocator_traits<CtrlBlockAlloc>::construct(ptr, 1, 0, alloc, std::forward<Args>(args)...);
	return /// shared_ptr<T>(ptr);
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

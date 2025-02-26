#include <iostream>

template <typename T>
struct Vector {
	T data[27] = {};
	std::size_t cap;
	std::size_t size;


private:
	struct iterator {
		T* elem;
	
		iterator(T* elem) : elem(elem) {}
		
		T& operator*() const noexcept {
			return *elem;
		}
		
		T* operator->() const noexcept {
			return elem;
		}

		iterator& operator++() {
			++elem;
			return *this;
		}

		bool operator!=(const iterator& other) {
			return other.elem != elem;
		}

	};

public:	
	iterator begin() {
		return iterator(data);
	}
	
	iterator end() {
		return iterator(data);
	}
	
};

struct Test {
	int a;
};

int main() {

	Vector<Test> vec;

	auto elem = vec.begin();

	for (auto elem : vec) {
		int x = 0;
	}

	elem->a = 27;

	++elem;

}



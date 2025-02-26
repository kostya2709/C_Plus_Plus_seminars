#include <iostream>

template <typename T>
struct Vector {
	T* data;
	size_t size;
	size_t cap;

private:
	class iterator {
		const T* elem;

	public:
		iterator(const T* elem) : elem(elem) {}

		const T& operator*() const {
			return *elem;
		}

		const T* operator->() {
			return elem;
		}

		iterator& operator++() {
			++elem;
			return *this;
		}

		bool operator!=(const iterator& other) const {
			return elem != other.elem;
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

int main() {


	const Vector<int> vec;
	vec.data = nullptr;	
	*vec.data = 0;
	auto iter = vec.begin();	

	for (int elem : vec) {
		std::cout << elem << " ok\n";
	}

}

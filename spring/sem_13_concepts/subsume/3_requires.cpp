#include <iostream>
#include <concepts>
#include <vector>
#include <list>

namespace detail {

template <typename T>
concept InputIterator = requires (T iter) {
	++iter;
	*iter;
};

template <typename T>
concept RandomIterator = InputIterator<T> && requires (T iter) {
	iter + 42;
};

template <InputIterator Iter>
void advance(Iter& iter, size_t n) {
	std::cout << "Input\n";
	for (size_t i = 0; i < n; ++i) {
		++iter;
	}
}

template <RandomIterator Iter>
void advance(Iter& iter, size_t n) {
	std::cout << "RandomAccess\n";
	iter += n;
}
};

int main() {
	std::vector vec{1, 2, 3, 4};
	auto iter1 = vec.begin();
	detail::advance(iter1, 1);
	
	std::list<int> list(10);
	auto iter2 = list.begin();
	detail::advance(iter2, 1);
}

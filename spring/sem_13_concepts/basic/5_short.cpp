#include <vector>
#include <iostream>

template <typename T>
concept InputIter = requires (T it) {
	++it; 
	*it;
};


template <InputIter Iter, typename T>
requires  requires (Iter it) {
	{ *it } -> std::convertible_to<std::remove_cvref_t<T>>;
}
Iter find(Iter begin, Iter end, const T& value) {
	for (auto iter = begin; iter != end; ++iter) {
		if (*iter == value) {
			return iter;
		}
	}
	return end;
}

int main() {

	std::vector vec{1, 2, 3, 4, 5};

	auto iter = find(vec.begin(), vec.end(), 3);
	std::cout << "Found: " << *iter << '\n';

// Some strange things
//	auto iter2 = find(vec.begin(), vec.end(), std::vector<int>{1, 2, 3});
}



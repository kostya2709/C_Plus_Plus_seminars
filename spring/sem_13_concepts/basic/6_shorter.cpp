#include <vector>
#include <iostream>

template <typename T>
concept InputIter = requires (T it) {
	++it; 
	*it;
	{ *it } -> std::convertible_to<typename std::iterator_traits<T>::value_type>;
};

auto find(InputIter auto begin, InputIter auto end, const auto& value) {
	for (auto iter = begin; iter != end; ++iter) {
		if (*iter == value) {
			return iter;
		}
	}
	return end;
}

int main() {

	std::vector vec{1, 2, 3, 4, 5};
	// InputIter auto test = vec.begin();

	auto iter = find(vec.begin(), vec.end(), 3);
	std::cout << "Found: " << *iter << '\n';

// Some strange things
//	auto iter2 = find(vec.begin(), vec.end(), std::vector<int>{1, 2, 3});
}



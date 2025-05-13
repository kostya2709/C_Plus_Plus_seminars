#include <vector>
#include <iostream>


template <typename InputIter, typename T>
requires requires (InputIter it) {
	++it; 
	*it;
	requires(std::is_same_v<T, std::decay_t<decltype(*it)>>);
}
InputIter find(InputIter begin, InputIter end, const T& value) {
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
	auto iter2 = find(vec.begin(), vec.end(), std::vector<int>{1, 2, 3});
}



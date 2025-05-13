#include <iostream>
#include <vector>
#include <algorithm>

void dump(std::vector<int>& vec) {
	for (auto elem : vec) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}

template <typename... Args>
void maybe_sort(Args... conds) {
	std::vector<int> vec{1, 4, 9, 12, 0};

	bool invert = false;
	auto cmp = [...conds=std::move(conds)](int x, int y) mutable {
		bool invert = (conds & ...);
		return invert ? x < y : x > y;
	};

	std::sort(vec.begin(), vec.end(), cmp);
	dump(vec);
}


int main() {
	maybe_sort(true, true, true, false);
}

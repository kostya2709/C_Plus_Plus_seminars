#include <memory>
#include <vector>
#include <iterator>

int main() {
	size_t len = 10;
	std::vector<std::unique_ptr<int>> vec;
	for (size_t i = 0; i < len; ++i) {
		vec.push_back(std::make_unique<int>(i));
	}
	
	std::vector<std::unique_ptr<int>> other1;
	std::copy(
		vec.begin(),
		vec.end(),
		std::back_inserter(other1)
	);

	std::vector<std::unique_ptr<int>> other2;
	std::copy(
		std::move_iterator(vec.begin()),
		std::move_iterator(vec.end()),
		std::back_inserter(other2)
	);
}

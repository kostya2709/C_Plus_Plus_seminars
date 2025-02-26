#include <sstream>
#include <iterator>
#include <vector>
#include <iostream>

int main() {
	std::ostringstream oss;
	std::vector<int> nums = {10, 20, 30};

	std::copy(
		nums.begin(),
		nums.end(),
		std::ostream_iterator<int>(oss, "-")
	);

	std::string result = oss.str();
	std::cout << result << '\n';
}

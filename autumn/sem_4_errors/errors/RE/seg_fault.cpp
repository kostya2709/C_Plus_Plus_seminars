#include <vector>

int main() {
	std::vector<int> vec = {1, 2, 3};
	vec[1000000] = 0;
}

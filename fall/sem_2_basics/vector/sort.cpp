#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6};
	
    std::sort(data.begin(), data.end());
    
	for (int i : data) {
		std::cout << i << '\n';
	}

	// std::sort(data.rbegin(), data.rend());
	// std::ranges::sort(data);

}

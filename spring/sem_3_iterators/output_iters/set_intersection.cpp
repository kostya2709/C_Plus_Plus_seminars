#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {

	std::set<int> set1{1, 5, 2, 6, 9};
	std::set<int> set2{1, 2, 3, 4, 5};

	std::vector<int> result;
	std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(result));

	for (auto elem : result) {
		std::cout << elem << std::endl;
	}

}



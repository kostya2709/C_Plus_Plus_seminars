#include <iostream>
#include <vector>

int main() {

	std::vector<int> vec{1, 2};
	std::vector<int>::iterator iter = vec.begin();

	std::cout << *iter << std::endl;
	++iter;
	
	std::cout << *iter << std::endl;
	++iter;

	std::cout << *iter << std::endl;
	++iter;

	std::cout << *iter << std::endl;
//	++iter;
//	--iter;
	iter -= 2;

	std::cout << *iter << std::endl;

}

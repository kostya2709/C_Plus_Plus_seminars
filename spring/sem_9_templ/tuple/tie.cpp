#include <tuple>
#include <iostream>


int main() {
	
	std::pair pair{1, 2};
	int one, two;

//	[one, two] = pair;
	
	std::tie(one, two) = pair;
	std::cout << one << ' ' << two << '\n';
}


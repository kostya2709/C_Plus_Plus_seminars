#include <string>
#include <iostream>
#include <vector>


int main() {
	
	std::vector<int> data = {1, 2, 3, 4, 5};	
	std::cout << data.front() << "\n";
	std::cout << data.back() << "\n";

	if (!data.empty()) {
		//
	}

	for (size_t i = 0; i != data.size(); ++i) {
    	std::cout << data[i] << " ";
	}

	std::cout << '\n';

	int x = 0;
    while (std::cin >> x) {
        data.push_back(x);
    }

    while (!data.empty()) {
    	std::cout << data.back(); 
        data.pop_back();
	}

}

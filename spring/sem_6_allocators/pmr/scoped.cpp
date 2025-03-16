#include <iostream>
#include <memory_resource>   // pmr core types
#include <vector>        	// pmr::vector
#include <string>        	// pmr::string
 
int main() {
	char buffer[256] = {}; // a small buffer on the stack
	std::fill_n(std::begin(buffer), std::size(buffer) - 1, '_');
	std::cout << buffer << '\n';
 
	std::pmr::monotonic_buffer_resource pool{std::data(buffer), std::size(buffer)};
 
	std::pmr::vector<std::pmr::string> vec{ &pool };
	vec.push_back("One");
	vec.push_back("Two");

	for (char c : buffer) {
		c = c >= ' ' ? c : '#';
		std::cout << c;
	}
}

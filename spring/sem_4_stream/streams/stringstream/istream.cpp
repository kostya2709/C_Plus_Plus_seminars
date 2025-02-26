#include <iostream>
#include <sstream>

int main() {
	std::string input = "42 3.1415";
	std::istringstream iss(input);
	
	int num;
	double d;
	iss >> num >> d;
	std::cout << "Num = " << num << "; d = " << d << std::endl;
}

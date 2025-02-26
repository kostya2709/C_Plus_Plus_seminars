#include <iostream>
#include <fstream>
 
int main() {
    std::ofstream out;
    
	out.open("hello.txt", std::ios::app);
    if (out.is_open()) {
        out << "Hello World!" << std::endl;
    } else {
		std::cout << "Failed to open file!\n";
	}
    out.close(); 
    
	std::cout << "File has been written" << std::endl;
}

#include <sstream>
#include <iostream>

int main(int argc, char* argv[])
{
    std::stringstream ss;
    ss << "42";
    
	int k = 0;
    ss >> k;
    std::cout << k << std::endl;
    
	return 0;
}

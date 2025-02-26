#include <sstream>
#include <iostream>

int main(int argc, char* argv[])
{
	int x = 2;
    std::ostringstream ss;
    ss << "4";
	ss << "2";
	std::cout << ss.str() << '\n';
    
	return 0;
}

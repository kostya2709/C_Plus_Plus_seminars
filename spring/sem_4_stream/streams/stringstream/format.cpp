#include <sstream>
#include <iostream>

void func(int id, const std::string& data1, const std::string& data2)
{
    std::stringstream ss;
    ss << "Operation with id = " << id << " failed, because data1 (" << data1 << ") is incompatible with data2 (" << data2 << ")\n";
    std::cerr << ss.str();
}

int main() {
	func(5, "DATA1", "DaTa_2");
}

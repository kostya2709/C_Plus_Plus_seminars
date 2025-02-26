#include <iostream>
#include <string>

void process(std::string_view sv) {
//	sv[0] = 0;
	std::cout << "Can process anything, e.g. this: " << sv << '\n';
}

void bad_process(const std::string& sv) {
	std::cout << "Can process anything, e.g. this: " << sv << '\n';
}

int main() {

	std::string str = "Hello, World!";
	const char* another_str = "Goodbye, World!";

	process(str);
	process("literal str");
	process(str.substr(0, 5));
	process(another_str);
	std::cout << "\n\n";

	bad_process(str);
	bad_process("literal str");
	bad_process(str.substr(0, 5));
	bad_process(another_str);
}

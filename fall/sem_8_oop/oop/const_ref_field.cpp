#include <iostream>

struct S {
	const int& r;
	S(): r(5) {}
};

struct S1 {
	const int& r;
};

int main() {
	int y = 9;
	S s;
	int x = 10;
	int u = 9;
	std::cout << s.r << '\n';
}

#include <iostream>

int main() {
	int x = 0;
	int* p = 0;
	p = &x;
	int* /*const*/ & r = ++p;
	--r;
	++*p;
	std::cout << x << *p << *r << '\n';
}
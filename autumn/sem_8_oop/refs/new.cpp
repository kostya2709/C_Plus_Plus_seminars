#include <iostream>

int f() {
	int* p = new int;
	return *p;
}

int main() {
	int x = f();
	delete &x;
}


#include <iostream>
#include <iostream>

struct Base {
	int x;
};

struct Derived : public Base {
	int y;
};

int main() {
	Derived d;
	printf("&d = %p, &d.x = %p, &d.y = %p\n", &d, &d.x, &d.y);
}

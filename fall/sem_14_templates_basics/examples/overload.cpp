#include <iostream>

template<typename T>
void foo(T var) {
	std::cout << "templ\n";
}

void foo(int) {
	std::cout << "not templ\n";
}

int main() {

	int x = 0;
	foo(x);

}



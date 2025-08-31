#include <typeinfo>

template <typename T>
class C { C() = delete; };

template<typename T>
void f(T& param) {
	C<T>();
}

int main() {

	int x = 27;			// x is an int
	const int cx = x;	// cx is a const int
	const int& rx = x;	// rx is a reference to x as a const int

//	f(x);
//	f(cx);
//	f(rx);
}

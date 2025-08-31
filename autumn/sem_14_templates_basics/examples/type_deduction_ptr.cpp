

template <typename T>
class C { C() = delete; };

template<typename T>
void f(T param) {
	C<T>();
}


int main() {

	const char* const str = "Hello world";

	f(str);
}

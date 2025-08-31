

template <typename T>
class C { C() = delete; };

template<typename T>
void f(T param) {
	C<T>();
}

template<typename T>
void f_ref(T& param) {
	C<T>();
}

int func(char, double) {
	return 27;
}


int main() {

// 	f(func);
	f_ref(func);
}

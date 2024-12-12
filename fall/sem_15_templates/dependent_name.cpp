template <typename T>
struct S {
	using A = int;
};

template <>
struct S<double> {
	static const int A = 5;
};

int x = 0;

template <typename T>
void f() {
	S<T>::A * x; // declaration or expression?
}

int main() {
//	f<double>();
	 f<int>();
}


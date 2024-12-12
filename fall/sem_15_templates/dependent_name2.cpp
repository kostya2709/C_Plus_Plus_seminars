template<typename T>
struct S {
	template<int N>
	void foo(int) {}
};
 
template<>
struct S<double> {
	const int foo = 1;
};

template<typename T>
void bar(int x, int y) {
	S<T> s;
	s.foo<5>(x + y); // function call or just two comparisons???
}

int main() {
//	bar<int>(0, 0);
	bar<double>(0, 0);
}

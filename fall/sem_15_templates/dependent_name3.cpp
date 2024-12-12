
template <typename T>
struct Base {
    int x;
};

template <typename T>
struct Derived : Base<T> {
    int f() { 
		return x;
	}
};

int main() {
    Derived<int> d;
    d.f();
    return 0;
}

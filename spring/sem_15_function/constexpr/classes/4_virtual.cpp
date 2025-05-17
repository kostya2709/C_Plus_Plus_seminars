
struct Base {
	constexpr virtual int foo(int x) {
		return x * 2;
	}
	
	constexpr virtual int bar(int x) {
		return x * 2;
	}
};

struct Derived : Base {
	constexpr virtual int foo(int x) override {
		return x * 3;
	}
	
	virtual int bar(int x) override {
		return x * 3;
	}
};

constexpr int test(bool is_base) {
	Derived d;
	Base b1;

	Base& b2 = d;

	if (is_base) {
		b1.bar(1);
		return b1.foo(1);
	} else {
		b2.bar(1);
		return b2.foo(1);
	}
}

int main() {
	static_assert(test(true) == 2);
	static_assert(test(false) == 3);
}

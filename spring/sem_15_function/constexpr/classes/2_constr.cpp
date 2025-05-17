

struct Test {
	int x = 0;
	double y = 1;

	constexpr Test(int x) : x(x) {}
};

constexpr int test() {
	Test test(0);
	return test.x;
}

int main() {
	static_assert(test() == 0);
}

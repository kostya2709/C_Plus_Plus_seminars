

struct Test {
	int x = 0;
	double y = 1;
};

constexpr int test() {
	Test test;
	return test.x;
}

int main() {
	static_assert(test() == 0);
}

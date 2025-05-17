#include <functional>
#include <iostream>

bool cmp_foo(int x, int y) {
	return x < y;
}

struct CmpFunctor {
	bool operator()(int x, int y) {
		return x < y;
	}
};

auto cmp_lambda = [](int x, int y) {
	return x < y;
};

int main() {

	std::function<bool(int, int)> cmp;

	cmp = cmp_foo;
	std::cout << cmp(1, 2) << '\n';
	
	cmp = CmpFunctor{};
	std::cout << cmp(1, 2) << '\n';

	cmp = cmp_lambda;
	std::cout << cmp(1, 2) << '\n';

}


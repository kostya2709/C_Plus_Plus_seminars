#include <functional>
#include <iostream>

struct NotFunctor {
	bool const_foo(int x, int y) const {
		const bool res = x < y;
		return param ? res : !res;
	}
	
	bool foo(int x, int y) {
		const bool res = x < y;
		return param ? res : !res;
	}

	int param{0};
};


int main() {

	std::function<bool(NotFunctor&, int, int)> cmp = &NotFunctor::const_foo;
	
	NotFunctor obj{0};
	std::cout << cmp(obj, 1, 2) << '\n';

	/*
	std::function<bool(const NotFunctor&, int, int)> cmp2 = &NotFunctor::foo;
	cmp2(obj, 1, 2);
	*/

	const std::function<bool(NotFunctor&, int, int)> cmp2 = &NotFunctor::foo;
	cmp2(obj, 1, 2);

}


#include <functional>
#include <iostream>


struct NotFunctor {
	bool foo(int x, int y) {
		const bool res = x < y;
		return param ? res : !res;
	}

	int param{0};
};


int main() {

	std::function<bool(NotFunctor&, int, int)> cmp = &NotFunctor::foo;
	
	NotFunctor obj{0};
	std::cout << cmp(obj, 1, 2) << '\n';
	


	std::function<int(NotFunctor&)> field = &NotFunctor::param;
	
	NotFunctor obj2{27};
	std::cout << field(obj2) << '\n';
}


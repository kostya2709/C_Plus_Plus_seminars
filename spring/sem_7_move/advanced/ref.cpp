#include <utility>

int& ret_ref() {}
int&& ret_ref_ref() {}

int main() {
	int x = 0;
	int& x_ref = x;
	int&& x_ref_ref = x;

	int& ref_0 = 0;
	int&& ref_ref_0 = 0;

	int& move_ref = std::move(x);
	int&& move_ref_ref = std::move(x);

	int& ref2 = x_ref_ref;
	int&& ref_ref2 = x_ref_ref;

	int& foo_ref1 = ret_ref();
	int&& foo_ref_ref1 = ret_ref_ref();

	int& foo_ref2 = ret_ref();
	int&& foo_ref_ref2 = ret_ref_ref();

	const int&& const_ref = std::move(x);
	int&& const_ref2 = std::move(const_ref);	

	const int& const_lvalue_ref = 27;
	const int&& const_rvalue_ref = 42;
	const_rvalue_ref = 27;
}

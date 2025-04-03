#include <utility>

template <typename T>
void check_type() = delete;

template <typename T>
void foo_val(T arg) {
	check_type<T>();
	check_type<decltype(arg)>();
}

template <typename T>
void foo_ref(T& arg) {
	check_type<T>();
	check_type<decltype(arg)>();
}

template <typename T>
void foo_uni(T&& arg) {
	check_type<T>();
	check_type<decltype(arg)>();
}

/*
void test_int() {
	foo_val(5);
	foo_ref(5);
	foo_uni(5);
}
*/

/*
void test_int_lref() {

	int x = 42;
	
	// int y = 0;
	// int& x = y;
	
	// int&& x = 42;

	foo_val(x);
	foo_ref(x);
	foo_uni(x);
}
*/


/*
void test_int_rref() {
	int x = 42;
	
	// int y = 0;
	// int& x = y;
	
	// int&& x = 42;

	foo_val(std::move(x));
	foo_ref(std::move(x));
	foo_uni(std::move(x));
}
*/

int main() {


}

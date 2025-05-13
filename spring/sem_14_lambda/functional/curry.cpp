#include <iostream>

auto curry(auto&& func, auto&&... set_args) {
	return [func=std::forward<decltype(func)>(func), ...set_args=std::forward<decltype(set_args)>(set_args)]
			(auto&&... args) -> decltype(auto) {
		return func(std::forward<decltype(set_args)>(set_args)..., std::forward<decltype(args)>(args)...);
	};
}

int main() {
	auto mul = [](int x, int y) { return x * y; };
	auto mul2 = curry(mul, 2);

	std::cout << "2 x 2 = " << mul2(2) << '\n';


	auto print = [](const std::string& str1, const std::string& str2, const std::string& str3) {
		std::cout << str1 << ' ';
		std::cout << str2 << ' ';
		std::cout << str3 << ' ';
		std::cout << '\n';
	};


	auto print_hello = curry(print, std::string("Hello"));
	auto print_hello_world = curry(print, "Hello", "World");
	auto print_hello_world_excl = curry(print, "Hello", "World", "!");

	print_hello(std::string("Mary"), std::string("Jane"));
	print_hello_world("?");
	print_hello_world_excl();

}

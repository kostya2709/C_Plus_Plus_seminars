#include <iostream>
#include <string>

int main() {

	auto do_twice = [](auto&& foo) {
		return [foo=std::forward<decltype(foo)>(foo)](const auto&... args) {
			foo(args...);
			foo(args...);
		};
	};

	auto hello_world = [](std::string str) {
		std::cout << "Hello, " << str << "!\n";
	};

	auto twice_hello = do_twice(hello_world);
	twice_hello("World");

}

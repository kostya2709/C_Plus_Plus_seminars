
#include "template_foo.hpp"
#include "template_class.hpp"

#include "lib.hpp"

#include <iostream>

int main() {
	int x = template_foo(6);
	TemplateClass<int> test(0);


	int y = lib_foo();

	std::cout << "Everything works!\n";

}

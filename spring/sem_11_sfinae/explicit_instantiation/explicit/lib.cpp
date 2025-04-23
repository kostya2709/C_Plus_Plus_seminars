#include "lib.hpp"

#include "template_foo.hpp"
#include "template_class.hpp"

int lib_foo() {

	TemplateClass<float> test(3.1415);
	return template_foo(test.getData());

}


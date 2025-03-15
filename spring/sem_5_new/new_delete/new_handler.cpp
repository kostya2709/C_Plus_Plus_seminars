#include <new>
#include <iostream>

void handler()
{
    std::cout << "Memory allocation failed, terminating\n";
    std::set_new_handler(nullptr);
}

void test_handler() {
	try {
		std::new_handler prev_handler = std::get_new_handler();
		std::cout << "Handler: " << prev_handler << '\n';
		prev_handler();
	
	} catch(...) {
		std::cout << "Caught\n";
	}
}

void test_alloc() {
    std::set_new_handler(handler);
    try {
        new int[1'000'000'000'000ul]();
    }
    catch (const std::bad_alloc& e) {
        std::cout << e.what() << '\n';
    }
}

int main() {

// 	test_handler();
	test_alloc();

}

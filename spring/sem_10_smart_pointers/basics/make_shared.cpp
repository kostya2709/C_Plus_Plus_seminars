#include <iostream>
#include <memory>

void print_count(const std::shared_ptr<int>& ptr) {
	static int cnt = 0;
	std::cout << ++cnt << ". count = " << ptr.use_count() << '\n';
}


int main() {

	auto ptr1 = std::make_shared<int>(42);
	print_count(ptr1);
	
	// auto ptr1 = std::shared_ptr<int>(new int(42));
}


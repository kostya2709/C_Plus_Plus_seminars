#include <iostream>
#include <memory>

void print_count(const std::shared_ptr<int>& ptr) {
	static int cnt = 0;
	std::cout << ++cnt << ". count = " << ptr.use_count() << '\n';
}

int main() {

	int* data = new int(27);
	
	std::shared_ptr<int> ptr1_1(data);
	auto ptr1_2 = ptr1_1;
	auto ptr1_3 = ptr1_2;
	print_count(ptr1_1);

	std::shared_ptr<int> ptr2_1(data);
	auto ptr2_2 = ptr2_1;

	print_count(ptr1_1);	
	print_count(ptr2_1);	
}

#include <iostream>
#include <memory>

void print_count(const std::shared_ptr<int>& ptr) {
	static int cnt = 0;
	std::cout << ++cnt << ". count = " << ptr.use_count() << '\n';
}


int main() {

	int* data = new int(27);

	std::shared_ptr<int> ptr0;
	print_count(ptr0);	

	std::shared_ptr<int> ptr1(data);
	print_count(ptr1);	
	
	auto ptr2 = ptr1;
	print_count(ptr1);
	
	auto ptr3 = std::move(ptr2);
	print_count(ptr1);
	
	ptr3.reset();
	print_count(ptr1);
	
	ptr2.reset();
	print_count(ptr1);

}

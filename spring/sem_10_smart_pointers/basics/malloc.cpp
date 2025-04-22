#include <iostream>
#include <memory>


struct MallocDeleter {
	void operator()(void* ptr) {
		std::cout << "Freed ptr\n";
		// ~T();
		free(ptr);
	}
};


int main() {

	int* data1 = new int(27);	
	std::shared_ptr<int> ptr1(data1);
/*	
	int* data2 = static_cast<int*>(calloc(1, sizeof(int)));	
	std::shared_ptr<int> ptr2(data2);
*/
	int* data3 = static_cast<int*>(calloc(1, sizeof(int)));	
	std::shared_ptr<int> ptr3(data3, MallocDeleter());
	
}

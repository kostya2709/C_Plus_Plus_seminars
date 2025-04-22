#include <memory>
#include <iostream>

struct Data {
	int x = 42;
};  

int main() {
    auto data_ptr = std::make_shared<Data>();  
    std::shared_ptr<int> x_ptr(data_ptr, &data_ptr->x);  


	std::cout << "use_count: " << data_ptr.use_count() << '\n';
    std::cout << "value: " << *x_ptr << '\n';
}

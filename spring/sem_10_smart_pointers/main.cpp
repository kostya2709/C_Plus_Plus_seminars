#include <iostream>
#include <memory>

struct Base {
	virtual ~Base() = default;
};  

struct Derived : Base {};  

template <typename T>
void check_cast(std::shared_ptr<T> ptr) {
    if (!ptr) {
		std::cout << "Cast failed\n";  
	} else {
		std::cout << "Cast succeded!\n";
	}
}

int main() {
    
	auto derived_ptr = std::make_shared<Derived>();  
	auto base_ptr = std::static_pointer_cast<Base>(derived_ptr);  
	check_cast(base_ptr);
    
	auto derived_back_ptr = std::dynamic_pointer_cast<Derived>(base_ptr);  
	check_cast(derived_back_ptr);
    
	
	auto base_ptr2 = std::make_shared<Base>();  
    auto derived_ptr2 = std::dynamic_pointer_cast<Derived>(base_ptr2);  
	check_cast(derived_ptr2);

}

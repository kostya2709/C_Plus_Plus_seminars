#include <iostream>
#include <memory>

struct Base { 
	~Base() {
		std::cout << "~Base\n";
	}
};  

struct Derived : Base {
   	~Derived() {
		std::cout << "~Derived\n";
		delete ptr_;
	}
private:
	int* ptr_{new int(27)};
};  

int main() {

	std::shared_ptr<Base> ptr(new Derived());

	auto derived_ptr = std::make_shared<Derived>();  
    std::shared_ptr<Base> base_ptr = derived_ptr;  
    derived_ptr.reset(); 
}  
